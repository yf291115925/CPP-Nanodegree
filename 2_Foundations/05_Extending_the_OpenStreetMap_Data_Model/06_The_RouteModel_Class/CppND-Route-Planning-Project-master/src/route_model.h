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
//因為Model 裡面只有一個Node 的資訊, 要能做A*, 你需要所有的Node,
//因此我們繼承Model 來造一個RouteModel 準備收集所有要用的Node 給A*

/*
Task:
In route_model.h:

Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.



*/
class RouteModel : public Model {

  public:
    //RouteModel 的 Node 也是繼承來的
    class Node : public Model::Node {
      public:
        // Add public Node variables and methods here.

        Node(){
            std::cout<<"RouteModel Init"<<"\n";
        }
        //因為有init 一個pointer parent_model, 因此一定要寫成 initial list 的方式
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {
            std::cout<<"RouteModel Init"<<"\n";
        }

      private:
        // Add private Node variables and methods here.
        int index;
        RouteModel * parent_model = nullptr;

    };

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
