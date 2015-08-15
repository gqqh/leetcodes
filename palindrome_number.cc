//判断一个int 数是不是回文数字。不用额外的空间。
//首先看这个数字有几位数，然后从中间截断，依次比较即可

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ) return false;
        if(x < 10) return true;

        int rest = 0;
        //
        for(int i = 9; i > 0; i--){
            if(x > power10(i)){
                // cout << i<<"|"<<x<<"|";
                rest = x % (power10((i+1)/2));
                x /= power10(i/2 + 1);
                // cout << x <<"|"<<rest<<endl;
                break;
            }
        }
        while(rest == revert_int(x)) return true;
        return false;
    }
private:
    int revert_int(int x){
        int ret = 0;
        while(x > 0){
            ret = ret *10 + x % 10;
            x /= 10;
        }
        return ret;
    }
    int power10(int x){
        int ret = 1;
        while(x-- > 0){
            ret *= 10;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    int t = 12344321;
    Solution test;
    cout << test.isPalindrome(t) << endl;

    return 0;
}
