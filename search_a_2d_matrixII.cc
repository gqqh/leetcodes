//从一个矩阵里找一个值value
//矩阵的特点是每一行从左到右有序，每一列从上到下都有序

//从右上角开始收索，如果target>matrix[i][j]，则向下走(i++),否则向左走(j--)。
//如果碰到边界(i >= m || j < 0)则退出

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    //算法复杂度为O(m+n)，每次向左或者向下走一步
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m <= 0) return false;
        int n = matrix[0].size();
        if(n <= 0) return false;

int compare = 0;
        //从右上角开始遍历
        int i = 0, j = n -1;
        bool flag = false;
        // matrix[i][j]在矩阵内
        while(i < m && j >= 0){
            if(matrix[i][j] == target){
                flag = true; compare++;
                break;
            }else if(target > matrix[i][j]) //目标值大，则向下走一步
                ++i;
            else //目标值小，则向左走一步
                --j;
    compare++;
        }

cout<<"比较 " << compare<<" 次."<<endl;
        return flag;
    }

    //上面的算法每次向左或者向下走一步，没有充分利用一行和一列都有序这个条件
    //每行每列都使用二分查找,结果反而慢了。。。。
    bool searchMatrix_b(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m <= 0) return false;
        int n = matrix[0].size();
        if(n <= 0) return false;
int compare = 0;
        //从右上角开始遍历
        // 保证如果target在矩阵里，必须在matrix[i][j]的左下角，包含matrix[i][j]
        int i = 0, j = n -1;
        bool flag = false;
        // matrix[i][j]在矩阵内
        while(i < m && j >= 0){
            if(matrix[i][j] == target){
                flag = true; compare++;
                break;
            }else if(target > matrix[i][j]){compare++;
                //目标值大，则向下走，增加i, 可以使用二分查找
                // 直到matrix[k-1][j] < target && matrix[k][j] >= target
                int b = i, e = m; //i,m均设为岗哨,
                // matrix[b][j]<target && matrix[e][j]>target
                while(b+1<e){
                    int mid = (b+e) / 2;compare++;
                    if(matrix[mid][j] >= target)
                        e = mid;
                    else
                        b = mid;
                }
                i = e;
            }else{
                //目标值小，则向左走减小j，可以使用二分查找
                // 直到matrix[i][k-1] <= target && matrix[i][k] > target
                int b = -1, e = j; //-1,j均设为岗哨,
                // matrix[i][b]<target && matrix[i][e]>target
                while(b+1<e){
                    int mid = (b+e) / 2;compare++;
                    if(matrix[i][mid] > target)
                        e = mid;
                    else
                        b = mid;
                }
                j = b;
            }
        }
cout<<"比较 " << compare<<" 次."<<endl;
        return flag;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<int> > v = {{1,   4,  7, 11, 15},
                              {2,   5,  8, 12, 19},
                              {3,   6,  9, 16, 22},
                              {10, 13, 14, 17, 24},
                              {18, 21, 23, 26, 30}};
    // vector<vector<int> > v = {{1,2,3,4,5}};
    // vector<vector<int> > v = {{5},{6}};
    Solution test;
    int n = 18;
    //命令行参数为2代表每行每列都二分找，否则为顺序找
    if(atoi(argv[1]) == 2)
        cout<<n<<"|二分|"<<test.searchMatrix_b(v, n)<<endl;
    else
        cout<<n<<"|顺序|"<<test.searchMatrix(v, n)<<endl;
    return 0;
}
