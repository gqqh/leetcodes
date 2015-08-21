//递归、尾递归
//用计算斐波那契数列的第n项演示
//f(n) = f(n-1) + f(n-2)
//f(1) = 1
//f(0) = 0
#include <iostream>
#include <cstdlib>
using namespace std;

//使用一步循环实现，极快
int fib1(int n){
    int a = 0, b = 1;
    for(int i = 0; i < n; i++){
        int tmp = a;
        a = b;
        b = b + tmp;
    }
    return a;
}

//直观的树形递归，极慢
int fib2(int n){
    if(n == 0 || n == 1)
        return n;
    else
        return fib2(n-1) + fib2(n-2);
}

//一种高效的递归实现（线形递归），需要优化为尾递归
int fib_rec1(int a, int b, int n){
    if(n == 0 || n == 1)
        return n;
    else
        return a + fib_rec1(b, a+b, n-1);//有个"a+"不是尾递归，编译器不会优化
}
int fib3(int n){
    return fib_rec1(0, 1, n);
}
//一种高效的递归实现，尾递归，使用变量a,b记录中间结果传递给下一次
int fib_rec2(int a, int b, int n){
    if(n == 0) return a;
    else
        return fib_rec2(b, a+b, n-1); //尾递归，编译器会进行优化不会导致栈溢出
}
int fib4(int n){
    return fib_rec2(0, 1, n);
}
int main(int argc, char const *argv[]) {
    int n = 10;
    if(argc == 2) n = atoi(argv[1]);
    // cout<<"fib1("<<n<<") "<<fib1(n)<<endl; //time ./a.out 100000000 30ms
    // cout<<"fib2("<<n<<") "<<fib2(n)<<endl;  //time ./a.out 50
    // cout<<"fib3("<<n<<") "<<fib3(n)<<endl;  //time ./a.out 50
    cout<<"fib4("<<n<<") "<<fib4(n)<<endl;  //time ./a.out 50
    return 0;
}
