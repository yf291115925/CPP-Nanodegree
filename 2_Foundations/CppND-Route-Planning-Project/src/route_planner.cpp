#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, 
                           float end_x, float end_y): m_Model(model) {
  start_x *= 0.01;
  start_y *= 0.01;
  end_x *= 0.01;
  end_y *= 0.01;

  start_node = &m_Model.FindClosestNode(start_x, start_y);
  end_node = &m_Model.FindClosestNode(end_x, end_y);
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
  distance = 0.f;
  std::vector<RouteModel::Node> path_found;
  RouteModel::Node parent;

  while (current_node->parent != nullptr) {
    path_found.push_back(*current_node);
    distance += current_node->distance(*(current_node->parent));
    current_node = current_node->parent;
  }
  // Still need to add start node
  path_found.push_back(*current_node);
  // Scale
  distance *= m_Model.MetricScale();
  return path_found;
}

void RoutePlanner::AStarSearch() {
  // Set start_node->visited to be true.
  start_node->visited = true;
  // Push start_node to the back of open_list.
  open_list.push_back(start_node);
  // Create a pointer RouteModel::Node *current_node 
  // and initialize the pointer to nullptr.
  RouteModel::Node *current_node = nullptr;

  // while the open_list size is greater than 0:
  while (open_list.size() > 0) {
    // Set the current_node pointer to the results of calling NextNode.
    current_node = NextNode();
    // if the distance from current_node to the end_node is 0:
    if (current_node->distance(*end_node) == 0) {
      // Call ConstructFinalPath using current_node and 
      // set m_Model.path with the results.
      m_Model.path = ConstructFinalPath(current_node);
      // Return to exit the A* search.
      return;
    }
    // else call AddNeighbors with the current_node.
    else {
      AddNeighbors(current_node);
    }
  }
}

float RoutePlanner::CalculateHValue(RouteModel::Node *node) {
  return node->distance(*end_node);
}

RouteModel::Node* RoutePlanner::NextNode() {
  std::sort(open_list.begin(), open_list.end(), [](const auto &a, const auto &b) {
    return a->h_value + a->g_value < b->h_value + b->g_value;
  });
  RouteModel::Node* next_node = open_list.front();
  open_list.erase(open_list.begin());
  return next_node;
}

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
  // Call FindNeighbors() on current_node to populate 
  // the current_node's neighbors vector.
  current_node->FindNeighbors();
  // For each neighbor in the current_node's neighbors
  for (auto neighbor: current_node->neighbors) {
    // Set the neighbors parent to the current_node.
    neighbor->parent = current_node;
    // Set the neighbor's g_value to the sum of the current_node's 
    // g_value plus the distance from the curent_node to the neighbor.
    neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
    // Set the neighbor's h_value using CalculateHValue
    neighbor->h_value = CalculateHValue(neighbor);
    // Push the neighbor to the back of the open_list.
    open_list.push_back(neighbor);
    // Mark the neighbor as visited.
    neighbor->visited = true;
  }
}
