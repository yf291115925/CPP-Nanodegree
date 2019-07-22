#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {

    //input from USER is 0~100, we treat it as the percentage of the map
    //convert input to percentage
    start_x*= 0.01;
    start_y*= 0.01;
    end_x*= 0.01;
    end_y*= 0.01;

    this->start_node = &m_Model->FindClosestNode(start_x,start_y);
    this->end_node =   &m_Model->FindClosestNode(end_x,end_y);


}
