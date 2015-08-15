//判断符号匹配，给定一个符号串，只包含'(',')','[',']','{', '}'
//([])[()]{[()]},都匹配，(]不匹配

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int l = s.size();
        vector<char> t(l);
        int j = 0;
        for(int i = 0, l = s.size(); i < l; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                t[j++] = s[i];
            else if(s[i] == ')' && j > 0 && t[j-1] == '(' ) j--;
            else if(s[i] == ']' && j > 0 && t[j-1] == '[' ) j--;
            else if(s[i] == '}' && j > 0 && t[j-1] == '{' ) j--;
            else return false;
        }
        return (j == 0 ? true : false);
    }
};
int main(int argc, char const *argv[]) {
    string s = "[({}()[])]";
    Solution test;
    cout << test.isValid(s)<<endl;
    return 0;
}
