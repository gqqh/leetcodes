//翻转一个unsigned int的bit位，例如0000..011翻转为110..0000

#include <iostream>
using namespace std;
typedef unsigned int uint32_t;
//使用一个临时变量和musk，如果n与musk按位与的结果为1，则对临时变量的第(31-i)位，
//置1.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t tmp = 0;
        uint32_t musk = 0x1;
        for(int i = 0; i < 32; i++){
            if(n & (musk << i))
                tmp |= (musk << (31-i));
        }
        return tmp;
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    unsigned int n = 43261596;
    cout << test.reverseBits(n) << endl;
    return 0;
}
