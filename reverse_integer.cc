//把一个数逆转，123-->321, -123 --> -321;

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if(x < 0){
            flag = false;
            x = 0-x;
        }
        long long int ret = 0;
        while(x > 0){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        //做溢出判断
        if(ret > INT_MAX || ret < INT_MIN) return 0;
        if(!flag) return 0-ret;
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    int t = -123;
    Solution test;
    cout << test.reverse(t)<<endl;
    return 0;
}
