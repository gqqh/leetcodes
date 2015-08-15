//实现atoi函数

#include <string>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int len = str.size();
        int l = 0;
        long long int ret = 0;
        //处理空格
        while(l < len && str[l] == ' ') l++;
        if(l == len) return 0; //全空格
        //处理符号
        bool flag = true;
        if(str[l] == '-'){
            flag = false;
            l++;
        }else if(str[l] == '+'){
            l++;
        }
        //数字
        while(l < len){
            if(str[l] > '9' || str[l] < '0'){ //碰到非数字，就只处理前面的数字
                break;
            }
            ret = ret * 10 - '0' + str[l];
            if(ret > INT_MAX) break;
            l++;
        }
        if(!flag) ret = 0-ret;
        if(ret > INT_MAX || ret < INT_MIN)
            return ret > 0 ? INT_MAX : INT_MIN;
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    string st = "-2147483649";
    Solution test;
    cout<<test.myAtoi(st)<<endl;
    return 0;
}
