//比较版本号，if version1 > version2 return 1, if version1 < version2 return -1,
//否则return 0，所有版本号均非空，并且只包含数字和'.'。
#include <iostream>
#include <string>

using namespace std;
//ord('.') == 46
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //使用'.'分割称若干个string字串，转换成int之后比较
        int size1 = version1.size();
        int size2 = version2.size();
        int b1 = 0, b2 = 0, len1, len2;

        while(b1 < size1 && b2 < size2){
            len1 = getch(version1, '.', b1);
            len2 = getch(version2, '.', b2);
            string st1 = version1.substr(b1, len1 - b1);
            string st2 = version2.substr(b2, len2 - b2);
            if(st1.empty() || st2.empty()) break;
            int a1 = stoi(st1);
            int a2 = stoi(st2);
            b1 = len1 + 1;
            b2 = len2 + 1;
            if(a1 == a2) continue;
            else if(a1 > a2) return 1;
            else return -1;
        }
        if(b1 < size1 && has_none_zero(version1, b1)) return 1;
        else if(b2 < size2 && has_none_zero(version2, b2)) return -1;
        else return 0;
    }
private:
    //从str的第b个字符开始往后遍历，返回ch的下标，不存在则返回n
    int getch(string str, char ch, int b){
        int i = b;
        int n = str.size();
        for(; i < n; i++){
            if(str[i] == ch) break;
        }
        return i;
    }
    //str从b开始如果有非0和'.'的字符，则返回true，否则返回false
    bool has_none_zero(string str, int b){
        int len = str.size();
        for(int i = b; i < len; i++){
            if(str[i] != '.' && str[i] != '0') return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    string version1 = "01.01";
    string version2 = "1.1.0.0.0";
    cout<<test.compareVersion(version1, version2)<<endl;
    return 0;
}
