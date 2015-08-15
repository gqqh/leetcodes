//找一组string中最长的公共前缀
//简单的从第一个字串中依次找一个字母往后遍历其他的字符串，
//如果不在某个字符串中则直接退出。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string ret;
        if(len < 1) return ret;
        if(len == 1) return strs[0];

        for(int i = 0, l = strs[0].size(); i < l; i++){
            bool flag = true;
            char ch = strs[0][i];
            for(int j = 1; j < len; j++){
                if(strs[j][i] != ch){ //string类的string[size()]会返回一个'\0'
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            ret.push_back(ch);
        }
        return ret;
    }
};
