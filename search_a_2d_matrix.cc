//从一个矩阵里找一个值value
//矩阵的特点是每一行从左到右有序，并且后一行都小于前一行
//
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //把二维的当成一维的进行二分查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n <= 0) return false;
        int m = matrix[0].size();
        if(m <= 0) return false;

        int b = 0, e = m * n - 1;
        while(b < e){
            int mid = (b + e) / 2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            else if(matrix[mid/m][mid%m] > target)
                e = mid - 1;
            else
                b = mid + 1;
        }
        if(matrix[b/m][b%m] == target)
            return true;
        return false;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<int> >v {{1,3,5,7},
                           {10,11,16,20},
                           {23,30,34,50}};
    int t = 34;
    Solution test;
    cout<<test.searchMatrix(v, t)<<endl;
    return 0;
}
