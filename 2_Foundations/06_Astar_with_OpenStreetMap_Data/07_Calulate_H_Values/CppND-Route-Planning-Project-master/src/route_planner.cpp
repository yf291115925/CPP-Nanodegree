#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {

    //input from USER is 0~100, we treat it as the percentage of the map
    //convert input to percentage
    start_x*= 0.01;
    start_y*= 0.01;
    end_x*= 0.01;
    end_y*= 0.01;

    this->start_node = &m_Model.FindClosestNode(start_x,start_y);
    this->end_node =   &m_Model.FindClosestNode(end_x,end_y);


    total_distance = 0.0;
}




/*

a.Iterate through the node parents until a node with parent
    equal to nullptr is reached - this will be the start node, which has no parent.
    Each node in the iteration should be pushed to the path_found vector.
b.To keep track of the total path distance, in each step of the iteration,
    add the distance between a node and its parent to the class distance variable.
c.Before the method returns, scale the distance by multiplying by the
    model's scale: m_Model.MetricScale().
    This is done since node coordinates are scaled down when they are stored in the model.
    They must be rescaled to get an accurate distance.
d.Return the path_found.

*/
std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node){

    std::vector<RouteModel::Node> path_found;

    RouteModel::Node tmpParentNode;

    while (current_node->parent != nullptr){

        path_found.push_back(*current_node);
        tmpParentNode = *(current_node->parent);
        this->total_distance += current_node->distance(tmpParentNode);
        //move cur_node pointer to its parent
        current_node = current_node->parent;

    }

    //push the current_node to vector, which is the start node
    path_found.push_back(*current_node);
    this->total_distance *= m_Model.MetricScale();

    return path_found;
}





/*
This time we make a STUB func for testing the env.

2.In route_planner.cpp define the AStarSearch method. The method should do the following:
    Set the parent of end_node to the start_node.
    Set m_Model.path to the result of calling ConstructFinalPath on end_node.

*/
//entry point
void RoutePlanner::AStarSearch(){

    //for testing only in this round.
    this->end_node->parent = this->start_node;
    m_Model.path = this->ConstructFinalPath(end_node);

    return ;
}




//The method should return the distance from the passed argument to the end_node.
float RoutePlanner::CalculateHValue(const RouteModel::Node* inputNode ){

    return inputNode->distance(*(this->end_node));

}
