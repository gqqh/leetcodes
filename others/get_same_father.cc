#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
  * git是一种分布式代码管理工具，git通过树的形式记录文件的更改历史，比如：
  *	base'<--base<--A<--A'
  *              ^
  *              | --- B<--B'
  * 小米工程师常常需要寻找两个分支最近的分割点，即base.
  * 假设git 树是多叉树，请实现一个算法，计算git树上任意两点的最近分割点。
  * （假设git树节点数为n,用邻接矩阵的形式表示git树：字符串数组matrix包含
  * n个字符串， 每个字符串由字符'0'或'1'组成，长度为n。
  * matrix[i][j]=='1'当且仅当git树种第i个和
  * 第j个节点有连接。节点0为git树的根节点。）
  *
  * 输入例子: [01011,10100,01000,10000,10000],1,2
  * 输出例子: 1
  */

class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     * 
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 
     *      当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
	    int len = matrix.size();
        int path1 = 0, path2 = 0;
        while(matrix[path1][indexA] != '1')
            path1++;

        while(matrix[path2][indexB] != '1')
            path2++;
        
        if(path1 > path2){
            int a = path1;
            while(path1 > path2){
                int b = 0;
                while(matrix[b][a] != '1')
                    b++;
                a = b;
                path1--;
            }
        }else{
            while(path2 > path1){
            	
            }
        }
        return;
    }
};

int main()
{
    Solution test;
    vector<string> matrix = {"01011", "10100", "01000", "10000", "10000"};
    int n1 = 1;
    int n2 = 2;

    cout<< test.getSplitNode(matrix, n1, n2) << endl;

    return 0;
}
