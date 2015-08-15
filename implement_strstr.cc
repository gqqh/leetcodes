//实现strstr函数
// #include <string.h>
//   char *strstr(const char *haystack, const char *needle);
//   The  strstr()  function  finds the first occurrence of the substring
//      needle in the string haystack.  The terminating null bytes ('\0')
//      are not compared.
//可以使用kmp算法，也可以使用BM算法，Sunday 算法
//这里使用sunday算法，简单高效
//sunday算法每次从最后往前匹配，
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size();
        int l = needle.size();
        if(l == 0) return 0;
        if(len == 0 || len < l) return -1;

        //len >= 1, l >= 1 , len >= l
        vector<int> pos(256, l+1); //pos放的初始值都是needle的长度+1
        for(int i = 0; i < l; i++)
            pos[needle[i]] = l-i;

        int j = 0;
        while(j <= len - l){
            int i = 0;
            while(i < l && haystack[j+i] == needle[i])
                i++;
            if(i == l)
                return j;
            else
                j += pos[haystack[j+l]];
        }
        return -1;
    }
};
int main(int argc, char const *argv[]) {
    string t1 = "mississippi", t2 = "a";
    Solution test;
    cout<<test.strStr(t1, t2)<<endl;
    return 0;
}
