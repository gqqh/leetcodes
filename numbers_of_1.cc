//返回一个unsigned int的1的个数
#include <iostream>
using namespace std;
/*
//使用掩码每次取出一个bit位，进行判断
typedef unsigned int uint32_t;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        uint32_t musk = 0x1;
        for(int i = 0; i < 32; i++){
            if(n & musk) ret += 1;
            musk <<= 1;
        }
        return ret;
    }
};
*/
//一个奇技淫巧的方法，适用于1比较少的数
typedef unsigned int uint32_t;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            n &= (n-1);
            ret ++;
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    unsigned int n = 1111;
    cout << test.hammingWeight(n) << endl;
    return 0;
}
