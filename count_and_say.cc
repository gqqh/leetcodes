//一个有意思的序列
//1，11,21,1211,111221,312211....
//这个题目需要一个str记录序列，并且需要一个vector记录上述string中
//某个数字有多少个连续的在一起。交叉循环

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret;
        if(n <= 0) return ret;
        ret.push_back('1');
        while(--n > 0){
            char ch = ret[0];
            vector<int> count;
            vector<char> chrs;

            int j = 1;
            int l = ret.size();
            //统计old retchar和count
            for(int i = 1; i < l; ++i){
                if(ret[i] == ret[i-1]){ //当前字符与之前相同
                    j++;
                }else{ //当前字符与之前不同
                    chrs.push_back(ch);
                    count.push_back(j);
                    ch = ret[i];
                    j = 1;
                }
            }
            count.push_back(j);
            chrs.push_back(ch);
            //生成新的ret
            ret.resize(0);
            for(int i = 0, t = count.size(); i < t; ++i){
                ret.push_back(count[i] + '0');
                ret.push_back(chrs[i]);
            }
        }

        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    int n = 1;
    if(argc == 2) n = atoi(argv[1]);
    cout<<"n = " << n << "|" << test.countAndSay(n)<<endl;
    return 0;
}
