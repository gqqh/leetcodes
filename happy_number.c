#include <stdio.h>
#include <stdlib.h>
//static int counts;
/**
  *Happy Number
  *  Write an algorithm to determine if a number is "happy".
  *  A happy number is a number defined by the following process: 
  *     Starting with any positive integer, replace the number by the 
  *     sum of the squares of its digits, and repeat the process 
  *     until the number equals 1 (where it will stay), or it loops 
  *     endlessly in a cycle which does not include 1. Those numbers for 
  *     which this process ends in 1 are happy numbers.
  * Example: 19 is a happy number
  *      12 + 92 = 82
  *      82 + 22 = 68
  *      62 + 82 = 100
  *      12 + 02 + 02 = 1
  */
/**
  *int的各个数字平方和小于810，可以做个简单的hash，flag[810]，重复了就赋1
  * 否则赋值0，一定会出现1重复的，当重复时如果是1，则成功，否则失败
  */
int getHappy(int a)
{
    int ret = 0;
    while(a > 0){
        int k = a % 10;
        ret += k * k;
        a /= 10;
    }
    return ret;
}
int isHappy(int a)
{
    if(a == 0)  return 0;
    if(a == 1)  return 1;

    //static default 0, int的各个数字的平方和小于810.
    static int flag[810];
    int t = getHappy(a);
    while(flag[t] != 1){
        flag[t] = 1;
 //       counts ++;
        t = getHappy(t);
    }

    if(t == 1)
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    int n = 19;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    if(isHappy(n))
        printf("%d is a happy number.\n", n);
    else
        printf("%d is not a happy number.\n", n);

  //  printf("counts:%d\n", counts);
    return 0;
}
