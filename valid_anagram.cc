/*
 *Valid Anagram
 * Given two strings s and t, write a function to determine if t is an
 * anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *Note:
 * You may assume the string contains only lowercase alphabets.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*判断两个单词是不是只是字母序不一样，简单点的就是对每个单词进行标识，统计每个
 *单词中每个字母出现的次数，例如“hello”-->e1h1l2o1，然后比较两个单词的这个标识
 *是否一样。
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    int l1 = s.size();
    int l2 = t.size();
    if(l1 != l2) return false;

    vector<int> st(256, 0);
    vector<int> tt(256, 0);
    for(int i = 0; i < l1; i++){
      st[s[i]]++;
      tt[t[i]]++;
    }
    if(st == tt)
      return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution test;
  string s = "anagram";
  string t = "nagarbm";
  cout<< test.isAnagram(s, t)<<endl;
  return 0;
}
