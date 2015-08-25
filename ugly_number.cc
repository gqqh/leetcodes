//判断一个数是否是丑数
//把只包含因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做是第一个丑数。

#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;

        while(num % 2 == 0) num >>= 1;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;

        return (num == 1);
    }
};
int main(int argc, char const *argv[]) {
    int n = 10;
    if(argc == 2) n = atoi(argv[1]);
    Solution test;
    cout<<n<<"|"<<test.isUgly(n)<<endl;
    return 0;
}
