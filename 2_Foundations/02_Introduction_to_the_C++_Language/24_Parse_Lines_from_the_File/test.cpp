void PrintVector(vector<int> v) {
  cout << "{ ";
  for (auto item : v) {
    cout << item << " ";
  }
  cout << "}" << "\n";
}

void TestParseLine() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "TestParseLine: ";
  string line = "0,1,0,0,0,0,";
  vector<int> solution_vect{0,1,0,0,0,0};
  vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    cout << "failed" << "\n";
    cout << "\n" << "Test input string: " << line << "\n";
    cout << "Your parsed line: ";
    PrintVector(test_vect);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
    cout << "\n" << "Test input string: " << line << "\n";
    cout << "Your parsed line vector: ";
    PrintVector(test_vect);
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}
