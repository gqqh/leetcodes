//求杨辉三角的第k行
// 第0行      1
// 第1行    1 2 1
// 第2行   1 3 3 1
// 第3行  1 4 6 4 1
// 第4行 1 5 10 10 5 1
//总结，当k>=1时，第k行有k+2个元素，从前往后分别是C（k+1, [0,...,k+1]）

#include <iostream>
#include <vector>
//从后面往前遍历，初始化全部为0，然后把最后一个置为1，每次把后一个元素加上它的
//前一个元素
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0){
            vector<int> tmp;
            return tmp;
        }
        vector<int> ret(rowIndex+1, 0);
        ret[rowIndex] = 1;
        for(int i = 0; i < rowIndex+1; ++i){
            for(int k = rowIndex-1; k > 0; --k)
                ret[k] += ret[k-1];
            ret[0] = 1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    int n = 6;
    if(argc == 2) n = atoi(argv[1]);

    vector<int> ret = test.getRow(n);
    for(auto i : ret) cout << i << " ";
    cout << endl;
    return 0;
}
