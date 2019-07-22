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
            std::cout<<"RouteModel Init"<<"\n";
        }
        //因為有init 一個pointer parent_model, 因此一定要寫成 initial list 的方式
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {
            //std::cout<<"create new Node idx:"<<idx<<"\n";
        }

      private:
        // Add private Node variables and methods here.

        //An int index.
        int index;
        //A pointer to a RouteModel object named parent_model. This variable is important,
        //as it allows each node to access data stored in the parent model that the node belongs to.
        RouteModel * parent_model = nullptr;

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
