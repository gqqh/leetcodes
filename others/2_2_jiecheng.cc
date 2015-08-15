//bop，阶乘的问题
//N!的二进制表示法中，最后有多少个0
//N!中的质因数2的个数为[N/2]+[N/4]+[N/8]+....+1
//类似与十进制的0个数跟质因数5的个数一样（因为2的个数肯定大于5的个数）
//N!的二进制中的0的个数只跟质因数2的个数有关

#include <iostream>
#include <cstdlib>

using namespace std;

/*
//求n!的二进制表示中末尾有多少个0
int func(int n){
    int ret = 0;
    while(n){
        n >>= 1;
        ret += n;
    }
    return ret;
}
*/

//奇技淫巧之，n!的二进制表示中末尾的0的个数等于，n-(n的二进制中1的个数)
int func(int n){
    int ret = n;
    while(n){
        n &= (n-1);
        ret -= 1;
    }
    return ret;
}
int main(int argc, char **argv)
{
    int n = 100;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    cout <<func(n)<<endl;
    return 0;
}
