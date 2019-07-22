#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    // constructor
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    
    // Public variables and method declarations
    float GetDistance() const {
      return distance;
    }
    void AStarSearch();

  private:
    // Private variables and method declarations
    float CalculateHValue(RouteModel::Node *node);
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node*);
    RouteModel::Node* NextNode();
    RouteModel &m_Model;
    RouteModel::Node *start_node;
    RouteModel::Node *end_node;
    float distance;
    std::vector<RouteModel::Node*> open_list;
    bool CompareNodes(RouteModel::Node* a, RouteModel::Node* b);
    void AddNeighbors(RouteModel::Node *node);
};

#endif