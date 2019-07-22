#include <algorithm>  // for sort
using std::sort;

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath};

// directional deltas, up,left,down,right
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};



/*
1.board

rowA = i,1,0,0,0,0,->ParseLine() only get rowA data, 0,1,0,0,0,0, size 6 = y direction
rowB = 0,1,0,0,0,0,
rowC = 0,1,0,0,0,0,
rowD = 0,1,0,0,0,0,
rowE = 0,0,0,0,1,g,


ReadBoardFile() append rowA -> rowE as grid. size 5 = x direction

so, the size becomes..

grid[comes from ReadBoardFile() size 5][comes from ParseLine() size 6]
turn to index
grid[0~4][0~5] or we can treat as gird[x][y]

goal point (4,5)
init point (0,0)

*/
//read char as the future cols, 0~5 = size 6
vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}

//append rows as the future rows, 0~4 = size 5
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


/**
 * Compare the F values of two cells.
 */
bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3]; // f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2;
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}


/**
 * Check that a cell is valid: on the grid, not an obstacle, and clear.
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;//return T or F
  return false;
}


/**
 * Add a node to the open list and mark it as open.
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
  // Add node to open vector, and mark grid cell as closed.
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}


/**
 * Expand current nodes's neighbors and add them to the open list.
 */
// TODO: ExpandNeighbors(arguments) {

  // TODO: Get current node's data.

  // TODO: Loop through current node's potential neighbors.

    // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.

      // TODO: Increment g value, compute h value, and add neighbor to open list.

// } TODO: End the function

/*
input:
reference of ...
    The current node,
    the open vector,
    the grid, and
    an int array for the goal coordinates.
*/
void ExpandNeighbors(vector<int> &current_node, int *goal, vector<vector<int>> &openlist,vector<vector<State>> &grid){

    //Get current node's data.
    int curx = current_node[0];
    int cury = current_node[1];
    int curg = current_node[2];
    int curh = current_node[3];
    int newg = curg+1;
    cout << __func__ << ", cru x:"<<curx<<", cur y:"<<cury<<"\n";
    //Loop through current node's potential neighbors.
    for(int i = 0; i < 4; i++){

        int poetential_x = curx +  delta[i][0];
        int poetential_y = cury +  delta[i][1];

        //Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        // if the point is State::kEmpty (which means not kObstcal, kPath)
        if (CheckValidCell(poetential_x, poetential_y, grid)){
            //Increment g value, compute h value, and add neighbor to open list
            //for future use.
            int newh =Heuristic(poetential_x,poetential_y,goal[0],goal[1]);
            cout<< poetential_x<<poetential_y<<goal[0]<<goal[1]<<newg<<newh<<"\n";
            AddToOpen(poetential_x, poetential_y, newg, newh, openlist, grid);

        }
    }

}



/**
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    // Get the next node
    CellSort(&open);
    auto current = open.back();
    open.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      return grid;
    }

    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "⛰️   ";
    case State::kEmpty: return "E   ";
    case State::kClosed: return "C   ";
    default: return "?   ";
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

#include "test.cpp"

int main() {
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);

  auto solution = Search(board, init, goal);
  PrintBoard(solution);
  // Tests
  TestHeuristic();
  TestAddToOpen();
  TestCompare();
  TestSearch();
  TestCheckValidCell();
  TestExpandNeighbors();
}
