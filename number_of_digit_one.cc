//给定一个整型数n，统计[0, n]中的所有数字中出现多少个1
//例如n = 13; return 6. [0, 13]:1,10,11,12,13

#include <iostream>
using namespace std;

class Solution {
public:
    //需要对每位数分析
    //例如:abcde如果考虑第三位为1的个数则
    //c == 0 : 有ab*100个
    //c == 1 ：有ab*100 + de + 1个
    //c > 1  ：有(ab+1)*100个
    int countDigitOne(int n) {
        //从低位开始求解
        if(n < 1) return 0;
        int ret = 0;
        long long int jie = 1;
        while(n / jie != 0 ){
            int t = n / jie;
            int c = t % 10;
            ret += t / 10 * jie;
            if(c == 1){
                ret += n % jie + 1;
            }else if(c > 1){
                ret += jie;
            }
            jie *= 10;
        }
        return ret;
    }
};
int main(int argc, char const *argv[]) {
    int n = 1410065408;
    Solution test;
    cout<<test.countDigitOne(n)<<endl;
    return 0;
}
