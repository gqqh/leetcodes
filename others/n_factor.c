#include <stdio.h>
#include <stdlib.h>

//通过移位相加计算阶乘，每次相加之后进行进位处理
#define N 40000
int main(int argc, char const *argv[]) {
  int num = 100;
  if(argc == 2){
    num = atoi(argv[1]);
  }
  /*计算100的阶乘*/
  int res[N] = {1};  //0的阶乘等于1,从右到左
  int len = 1;        //位数

  int i, m;
  for(i = 1; i < N; ++i) //清零所有高位
    res[i] = 0;
  for(m = 2; m <= num; ++m){ //x2 x3 ,,, xnum
    for(i = 0; i < len; ++i) //xm
      res[i] *= m;
    for(i = 0; i < len; ++i){ //处理进位
      if(res[i] >= 10){
        res[i+1] += res[i] / 10;
        res[i] %= 10;
      }
    }
    while(res[len] != 0){ //处理最高位的进位
      res[len + 1] = res[len] / 10;
      res[len] %= 10;
      len ++;
    }
  }
  printf("%d ! = \n", num);
  for(i = 0; i < len; i++)
    putchar('0' + res[len-1-i]);
  if(len > 20)
    putchar('L');
  putchar(10);
  return 0;
}
