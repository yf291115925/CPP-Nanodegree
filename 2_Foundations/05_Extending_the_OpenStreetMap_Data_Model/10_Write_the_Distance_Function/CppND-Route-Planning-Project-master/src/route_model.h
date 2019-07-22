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
//因為Model是應付直接loadXML時裝的data, 裡面只有一個Node.x=lon, Node.y=lat 經緯度 的資訊, 要能做A*, 需要Node x,y,g,h,
//因此我們繼承Model 來造一個RouteModel 準備蒐集足夠的資訊的 Node 給A*, 所以下面才要加那些private 的變數

/*
Task:
In route_model.h:

Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.



*/
class RouteModel : public Model {

  public:

    //RouteModel 的 Node 也是繼承來的
    /*
    The Node Class
    The Model::Node class that exists in the current code doesn't contain all the data that would be needed to perfom an A* search.
    In order to perform a search, it would be ideal for each node to contain at least the following information:

        1.The g-value for the node.
        2.The h-value for the node.
        3.A boolean to indicate if the node has been visited.
        4.A pointer to the node's parent.

    In this exercise, you will fill out the RouteModel::Node class in route_model.h, which will extend the Model::Node class
    so that the data above, along with a few other useful variables, can be included with each node.
    Note that the RouteModel::Node class already has the following private variables:

        1.An int index.
        2.A pointer to a RouteModel object named parent_model. This variable is important,
            as it allows each node to access data stored in the parent model that the node belongs to.

    To complete this exercise:
    Add the following public variables to the RouteModel::Node class:
        1.A Node pointer parent, which is initialized to a nullptr.
        2.A float h_value, which is initialized to the maximum possible: std::numeric_limits<float>::max().
        3.A float g_value, which is initialized to 0.0.
        4.A bool visited, which is initialized to false.
        5.A vector of Node pointers named neighbors.

    Pass testing:
        [==========] Running 2 tests from 1 test case.
        [----------] Global test environment set-up.
        [----------] 2 tests from RouteModelTest
        [ RUN      ] RouteModelTest.RouteModelData
        [       OK ] RouteModelTest.RouteModelData (67 ms)
        [ RUN      ] RouteModelTest.RouteModelNode
        RouteModel Init
        RouteModel Init
        [       OK ] RouteModelTest.RouteModelNode (61 ms)
        [----------] 2 tests from RouteModelTest (128 ms total)

        [----------] Global test environment tear-down
        [==========] 2 tests from 1 test case ran. (128 ms total)
        [  PASSED  ] 2 tests.


    */
    class Node : public Model::Node {

      public:

        //Add
        Node * parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node*> neighbors;


        /*
        Write the Distance Function
        As you write A* search, it will be useful to be able to find the distance between two nodes. This will allow the search algorithm to find the closest node to the current node. In this exercise, you will write a utility function that finds the distance between two RouteModel::Node objects.

        To complete this exercise:
        Add a distance declaration to the RouteModel::Node class in route_model.h.
        This method should take a Node object as the argument, and it should return a float.
        The distance method shouldn't change the object being passed, so you can make it a const method (add const after the function name).
        Return the euclidean distance from the current node to the node passed in.

        */
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

  private:
    // Add private RouteModel variables and methods here.

    //Taks1:Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
    //這個m_Nodes 會拿來存所有open street map 的 data, 之後給Astar 用
    std::vector<Node> m_Nodes;
};
