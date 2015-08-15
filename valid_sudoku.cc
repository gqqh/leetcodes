//判断一个数独库是不是合法的，也就是有没有解。
//这个是简单版的，只验证已经填入的是不是合法即可。
//判断已经填入的几个是不是合法，主要是九行九列，以及九个三宫格

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //判断行和列
        for(int i = 0; i < 9; i++){
            vector<bool> flag_row(9, false);
            vector<bool> flag_col(9, false);
            for(int j = 0; j < 9; j++){
                //判断行
                if(board[i][j] != '.' && flag_row[board[i][j] - '0'])
                    return false;
                else if(board[i][j] != '.'){
                    flag_row[board[i][j] - '0'] = true;
                }
                //判断列
                if(board[j][i] != '.' && flag_col[board[j][i] - '0'])
                    return false;
                else if(board[j][i] != '.')
                    flag_col[board[j][i] - '0'] = true;
            }
        }
        //判断每一个三宫格
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                //依次定位到每个三宫格
                vector<bool> flag(9, false);
                for(int k = 0; k < 9; k++){
                    if(board[i+k/3][j+k%3] == '.')
                        continue;
                    else if(flag[board[i+k/3][j+k%3] - '0'])
                        return false;
                    else
                        flag[board[i+k/3][j+k%3] - '0'] = true;
                }
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char> > board ={{'.','.','.', '.','5','.', '.','1','.'},
                                  {'.','4','.', '3','.','.', '.','.','.'},
                                  {'.','.','.', '.','.','1', '.','.','1'},

                                  {'8','.','.', '.','.','.', '.','2','.'},
                                  {'.','.','2', '.','7','.', '.','.','.'},
                                  {'.','1','5', '.','.','.', '.','.','.'},

                                  {'.','.','.', '.','.','2', '.','.','.'},
                                  {'.','2','.', '9','.','.', '.','.','.'},
                                  {'.','.','4', '.','.','.', '.','.','.'}};
    Solution test;
    cout<<test.isValidSudoku(board)<<endl;
    return 0;
}
