//求杨辉三角的前k行， k = 5；
// 第0行      1
// 第1行     1 1
// 第2行    1 2 1
// 第3行   1 3 3 1
// 第4行  1 4 6 4 1
//总结，当k>=1时，k行有k个元素，从前往后分别是C（k-1, [0,...,k-1]）

#include <iostream>
#include <vector>
//从后面往前遍历，初始化全部为0，然后把最后一个置为1，每次把后一个元素加上它的
//前一个元素
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows <= 0) return ret;
        vector<int> r = {1};
        ret.push_back(r);
        for(int i = 1; i < numRows; i++){
            r.resize(0);
            r.push_back(1);
            for(int j = 1; j < i; j++)
                r.push_back(ret[i-1][j-1]+ret[i-1][j]);
            r.push_back(1);
            ret.push_back(r);
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    int n = 6;
    if(argc == 2) n = atoi(argv[1]);

    vector<vector<int> > ret = test.generate(n);
    for(auto i : ret){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
