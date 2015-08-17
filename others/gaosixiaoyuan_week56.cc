/*
 *高斯消元.一
 *[http://hihocoder.com/contest/hiho56/problem/1]
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define N 500
#define M (2 * N)
double matrix[M+1][N+1]; //保证精度

//求double类型的约等于值
bool eq_zero(double f){
  return ((f <= 1e-8) && (f >= -1e-8));
}

int main(int argc, char const *argv[]) {
   //input data
   int n, m;
   cin>> n >> m;
   for(int i = 0; i < m; ++i){
     for(int j = 0; j < n+1; ++j)
      cin>>matrix[i][j];
   }

   //化简为上三角行列式
   for(int i = 0; i < n; ++i){ //n列
     bool flag = false; //是否找到一个matrix[j][i] != 0
     //从第i..m-1行，找到一个j，使得matrix[j][i] != 0，如果找不到就继续下一列
     for(int j = i; j < m; ++j){//m行
       if(!eq_zero(matrix[j][i])){
         //交换第j行和第i行，matrix[i][0..i-1],matrix[j][0..i-1]都是0
         swap(matrix[j], matrix[i]);
         flag = true;
         break;
       }//end if
     }//end for
     if(!flag) continue;

     //当matrix[i][i]!=0时消元，第i+1..m-1行，每列以matrix[i][i]为轴，进行消元
     for(int j = i+1; j < m; ++j){
       if(eq_zero(matrix[j][i])) continue;
       double t = matrix[i][i] / matrix[j][i];
       for(int l = i; l < n+1; ++l){
           matrix[j][l] = matrix[j][l] * t - matrix[i][l];
         }
       }//end for
     }//end for

   //从下往上迭代求解上三角式
   //先检查是否无解或者多解，若matrix[n-1][n-1]
   if(eq_zero(matrix[n-1][n-1]) && eq_zero(matrix[n-1][n])){
     cout<<"Many solutions";
     return 1;
   }
   for(int i = 0; i < m; ++i){
     bool flag = true; //true-->全为0
     for(int j = 0; j < n; ++j){
       if(!eq_zero(matrix[i][j])){
         flag = false;
         break;
       }
     }
     if(flag && !eq_zero(matrix[i][n])){
       cout<<"No solutions";
       return 2;
     }
   }//end for
   //此时存在唯一解
   for(int i = n - 1; i >= 0; --i){
     matrix[i][n] /= matrix[i][i];
     matrix[i][i] = 1;
     for(int j = i-1; j >= 0; --j){
       matrix[j][n] -= matrix[i][n] * matrix[j][i];
       matrix[j][i] = 0;
     }
   }
   for(int i = 0; i < n; ++i){
     if(matrix[i][n] < 0)
      cout << (int)(matrix[i][n] - 1e-8) << endl;
     else
      cout << (int)(matrix[i][n] + 1e-8) << endl;
   }

   return 0;
 }
