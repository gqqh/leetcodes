//求一个0、1矩阵中最大的全1方阵大小
//使用动态规划，类似与LCS算法
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //动态规划，使用一个二数组dp[][]来表示，同时max记录最大的边长
    // dp[x][y] = min(dp[x][y-1], dp[x-1][y], dp[x-1][y-1]) + 1
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows < 1) return 0;
        int cols = matrix[0].size();
        if(cols < 1) return 0;

        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        int max = 0;
        for(int j = 0; j < cols; j++){
            dp[0][j] = matrix[0][j] - '0';
            if(dp[0][j] == 1) max = 1;
            cout<<dp[0][j]<<endl;
        }
        for(int i = 0; i < rows; i++){
            dp[i][0] = matrix[i][0] - '0';
            if(dp[i][0] == 1) max = 1;
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else{
                    dp[i][j] = min_tri(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                    max = dp[i][j] > max ? dp[i][j] : max;
                }
            }
        }
        return max * max;
    }
private:
    //返回a,b,c中的最小值
    inline int min_tri(int a, int b, int c){
        a = a < b ? a : b;
        return (a < c ? a : c);
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char> > v = {{'1'}};
    Solution test;
    cout<<test.maximalSquare(v)<<endl;
    return 0;
}
