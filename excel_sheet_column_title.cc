//把一个正整数，转换成26进制的数 1->A,...,26->Z,27->AA,28->AB

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
//近似可以理解为26进制，其中1->A,...25->Y,0->Z，并且当0->Z时，要把原来的数
//减去1
class Solution {
public:
    string convertToTitle(int n) {
        vector<char> alp;
        vector<char> ans;
        string ret;
        alp.push_back('A');
        int t;
        for(int i = 1; i <= 26; ++i)
            alp.push_back('A'+i-1);

        while(n > 0){
            t = n % 26;
            if(t == 0){
                ans.push_back('Z');
                n -= 1;
            }else{
                ans.push_back(alp[t]);
            }
            n /= 26;
        }
        int len = ans.size();
        for(int i = len-1; i >= 0; --i){
            ret.push_back(ans[i]);
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    int n = 27;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    cout << test.convertToTitle(n)<<endl;
    return 0;
}
