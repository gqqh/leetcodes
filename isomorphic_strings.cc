//判断两个字符串是否是同构字符串
//"egg", "add" -->true
//"foo", "bar" -->false
//"paper", "title" -->yes

//使用两个数组分别表示当前字母最近一次出现的位置，如果都相同则同构，否则不是
//该数组初始化为全-1，每次访问一个字母后，更新数组中该字母的位置

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        if(l1 != l2) return false;
        if(l1 <= 1) return true;

        //两个统计用的字母表
        vector<int> table0(256, -1);
        vector<int> table1(256, -1);

        for(int i = 0; i < l1; i++){
            if(table0[s[i]] != table1[t[i]])
                return false;
            table0[s[i]] = i;
            table1[t[i]] = i;
        }
        return true;
    }
};
