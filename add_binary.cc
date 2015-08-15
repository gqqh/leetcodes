//二进制加法，给两个二进制的bit流，返回一个二进制流

#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.size()-1;
        int l2 = b.size()-1;
        if(l1 < 0) return b;
        if(l2 < 0) return a;

        int acc = 0;
        int base = 2 * '0';
        string ret;
        while (l1 >= 0 && l2 >= 0) {
            int t = a[l1--] + b[l2--] + acc  - base;
            if( t < 2){
                acc = 0;
                ret.push_back(t + '0');
            }else{
                acc = 1;
                ret.push_back(t-2+'0');
            }
        }
        while(l1 >= 0){
            int t = a[l1--] + acc - '0';
            if(t < 2){
                acc = 0;
                ret.push_back(t+'0');
            }else{
                acc = 1;
                ret.push_back('0');
            }
        }
        while(l2 >= 0){
            int t = b[l2--] + acc - '0';
            if(t < 2){
                acc = 0;
                ret.push_back(t+'0');
            }else{
                acc = 1;
                ret.push_back('0');
            }
        }
        if(acc) ret.push_back('1');
        for(int b = 0, e = ret.size()-1; b < e; b++, e--){
            char t = ret[b];
            ret[b] = ret[e];
            ret[e] = t;
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    string s1 = "1111";
    string s2 = "11";
    cout <<test.addBinary(s1, s2) << endl;
    return 0;
}
