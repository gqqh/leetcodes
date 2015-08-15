//两个将不能对面，写出只用一个变量就列举出所有可能的位置
// 1--2--3
// 4--5--6
// 7--8--9

//使用位域，表示无符号
//位域需要注意的：
//1）每个位域成员最好不要超过8bits，最好是int,unsigned int或者signed int这三种
//2）位域地址对齐问题，在相邻的两个来相同类型之间进行压缩
//3）位域的成员不能用&取地址，因为位域是按位寻址，&是按字节寻址。
#include <iostream>

using namespace std;

//使用位域的一个字节，表示两个变量
struct ab_node{
        unsigned char a:4;
        unsigned char b:4;
};
int main(int argc, char const *argv[]) {
    struct ab_node t;
    for(t.a = 1; t.a <= 9; t.a++){
        for(t.b = 1; t.b <= 9; t.b++){
            if(t.a % 3 == t.b % 3) continue;
            cout << "A = "<< (int)t.a <<", B = "<< (int)t.b<<endl;
        }
    }
    return 0;
}
