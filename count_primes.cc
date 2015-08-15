//统计<n的素数的个数

//使用一个全为0的数组，当其置为1时表示这个数非素数
//依次把每个数的k倍的地方置1

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        int ret = 0;
        for(int i = 2; i < n; i++){
            if(is_prime(i))
                ret++;
        }

        return ret;
    }
private:
    bool is_prime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    int t = 10;
    if(argc == 2) t = atoi(argv[1]);
    Solution test;
    cout << test.countPrimes(t)<<endl;
    return 0;
}
