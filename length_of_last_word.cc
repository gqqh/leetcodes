//一个字符串只有大小写字母和空格组成，求最后一个单词的长度

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        if(l == 0) return 0;

        int ret = 0;
        while(--l >= 0 && s[l] == ' ');
        if(l >= 0){
            cout<<l<<"|"<<s[l]<<endl;
            ret++;
            while(--l >= 0 && s[l] != ' ') ret++;
        }
        return ret;

    }
};
int main(int argc, char const *argv[]) {
    string s = "";
    Solution test;
    cout<<test.lengthOfLastWord(s)<<endl;

    return 0;
}
