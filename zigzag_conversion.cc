//把一个字符串进行"之"字形转码，然后按行从新编码
//nRows限制了，之字形有多少行。
//分析发现，没一行的第一个跟下一个之间是有规律的，
// 第i行每个数加上 t = 2(n-1) - [2(n-i-1)];第1行和最后一行为[2(n-1)]

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        if(s.empty() || numRows <= 0) return ret;
        if(numRows == 1) return s;

        int len = s.size();
        int gap = 2 * (numRows - 1);
        for(int i = 0; i < numRows; i++){
            int j = i;
            int t = gap - 2 * i;
            if(t == 0) t = gap;

            cout << i << endl;
            while(j < len){
                cout<<j<<"|"<<s[j]<<"|"<<t<<endl;
                ret.push_back(s[j]);
                j += t;
                t = gap - t; //t的变换要下轮生效
                if(t == 0) t = gap;
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    string s = "0123456789abcdefghijklmnopqrstuvwxyz";
    int n = 2;
    Solution test;
    cout << test.convert(s, n)<<endl;
    return 0;
}
