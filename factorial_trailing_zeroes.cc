//求一个数的阶乘后面零的个数，有规律可循
//f(n) = {sum(i) | n > 0;i = n / 5; n = i;}

#include <iostream>
#include <cstdlib>

using namespace std;
//只需要统计其中5的个数即可，n=100,[100/5]=20,[20/5]=4,[4/5]=0,20+4=24
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n > 0){
            n = n / 5;
            ret += n;
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    int n = 100;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    cout << "n = " << n << endl;
    cout << test.trailingZeroes(n) << endl;
    return 0;
}
