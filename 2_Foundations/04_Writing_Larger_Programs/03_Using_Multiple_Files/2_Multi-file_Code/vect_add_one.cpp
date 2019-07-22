//其實不需要, 在cpp 只要有實做 AddOneToEach 即可
//#include "vect_add_one.h"

//這個 AddOneToEach 實做會被搜到是因為build command 有link到這個檔, 跟include 無關



#include<vector>
using std::vector;

void AddOneToEach(vector<int> &v) {
    for (auto& i: v) {
        i++;
    }
}
