#pragma once
/*
route_model.h and route_model.cpp
These files contain class stubs which will be used to extend the Model and Node data structures
from model.h and model.cpp using "class inheritance".

Remember that inheritance in this case will you
to use all of the PUBLIC methods and attributes of the Model and Node classes in the derived classes.
You will be filling out the classes in route_model.h and route_model.cpp over the course of your project.

*/
#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:

    class Node : public Model::Node {

      public:

        //Add
        Node * parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node*> neighbors;

        //寫在Node 裡面, 求自己Node和其他人的距離
        float distance(Node other) const {
            //Model 的 node.x node.y 已經在 Model 的 constructor AdjustCoordinates() 轉成 (x,y) 了

            //euclidean distance
            return  std::sqrt(    std::pow((x-other.x),2) +  std::pow((y-other.y),2)      );
        }


        // Add public Node variables and methods here.
        Node(){
            std::cout<<"Empty Constructor RouteModel Init"<<"\n";
        }
        //因為有init 一個pointer parent_model, 因此一定要寫成 initial list 的方式
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {
            //std::cout<<"create new Node idx:"<<idx<<"\n";
        }


        //This method will be called from route_planner.cpp, so the method needs to be public
        //找出當下nodes vs 所有有經過此node 的 roadS 哪個才是他的最近road
        //Since FindNeighbors operates on the current Node and modifies the Node data,
        //it does not need any arguments and can have return type void.
        void FindNeighbors();


      private:
        // Add private Node variables and methods here.

        //An int index.
        int index;
        //A pointer to a RouteModel object named parent_model. This variable is important,
        //as it allows each node to access data stored in the parent model that the node belongs to.
        //可以讓被創建的 Node 反查自己的RouteModel 是誰, 應該都一樣, 目前唯一只有一個 RouteModel
        RouteModel * parent_model = nullptr;


        // get a pointer to the closest unvisited node from a vector of node indices(each node treat as current node)
        // 尋找node_indices 們中, 和當下這個Node 最近的是誰, return 此Node pointer

        // 而 node_indices 就是那些含有current node 的 Roads 所帶來的 node_indices
        //ex road1 road2 都有包含當下此Node, 那就把 road1 上有的 node_indices1 丟近來, 當中找誰和current node 最近
        // 當然 node_indices2 也會近來找
        RouteModel::Node* FindNeighbor(std::vector<int> node_indices);

    };//end of class Node

    // Add public RouteModel variables and methods here.
    RouteModel(const std::vector<std::byte> &xml);

    //這個 path 最後會存著結果
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

    //Task2:Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.
    std::vector<Node>& SNodes(){
        return m_Nodes;
    }

    //only for testing
    std::unordered_map<  int, std::vector<const Model::Road*>  >&
    GetNodeToRoadMap(){
        return node_to_road;
    }



    //for dealling user input x,y
    RouteModel::Node& FindClosestNode(float x,float y);

  private:
    // Add private RouteModel variables and methods here.
    std::vector<Node> m_Nodes;

    //Add
    std::unordered_map<  int, std::vector<const Model::Road*>  > node_to_road;

    //Add 建出一個Node 和 屬於他的Road 的對照表, 只會在RouteModel 內部用到
    //放 private 即可, 因為裡面操作都是用RouteModel 內部變數, 不需要input, 且都是
    //pointer or reference, 所以也不用回, 在cpp 實做
    void CreateNodeToRoadHashmap();


};
