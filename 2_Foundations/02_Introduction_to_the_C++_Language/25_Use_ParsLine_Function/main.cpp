#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;


vector<int> ParseLine_row(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

// TODO: Change the return type of ReadBoardFile.
vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  // TODO: Declare an empty board variable here with
  // type vector<vector<int>>.
  vector<vector<int>> board;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      // TODO: Replace the "cout" code with a call to ParseLine for each line and push the results of ParseLine to the back of the board.
      board.push_back(ParseLine_row(line));
      //cout << line << "\n";
    }
  }
  // TODO: Return the board variable.
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Store the output of ReadBoardFile in the "board" variable.
  vector<vector<int>> board;
  board = ReadBoardFile("1.board");
  // TODO: Uncomment PrintBoard below to print "board".
  PrintBoard(board);
}
