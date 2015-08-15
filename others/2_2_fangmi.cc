//给定一个数，判断它是否为2的方幂
#include <iostream>
#include <cstdlib>
using namespace std;

/*
//统计1的个数，为1则是，否则不是
bool func(int n){
    int ret = 0;
    while(n){
        n &= (n-1);
        ret++;
    }
    return ret == 1 ? true : false;
}*/
//奇技淫巧
bool func(unsigned int n){
    return (n > 0 && ((n&(n-1)) == 0)) ? 1 : 0;
}
int main(int argc, char const *argv[]) {
    int n = 1024;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    cout << func(n) << endl;

    return 0;
}
