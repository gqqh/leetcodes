//把一个非负的整数，转换成英语的表达方式
//
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    //把一个数按照英式记法标记为三个数一段，从后往前每三位保存一起，
    // 然后从从高位到低位依次是判断百位，十位和个位；特别注意在判断十位之前
    // 要跟20比较一下；大于等于20的处理，小于20的直接输入；
    // 有几个细节，例如使用三个table分别表示三种特别情况；
    // 表中有空的，其余每个数前面有个空格，因为格式， 最后再把第一个空格去掉。
    string numberToWords(int num) {
        string ret;
        if(num < 0) return ret;
        if(num == 0) return "Zero";

        //0-19
        vector<string> table1{
            "", " One", " Two", " Three", " Four", " Five", " Six", " Seven",
            " Eight", " Nine",
            " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen",
            " Sixteen", " Seventeen", " Eighteen", " Nineteen"
        };
        //20,30,...90
        vector<string> table2{
            "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty",
            " Seventy", " Eighty", " Ninety"
        };
        //三位一个域，为千，百万，billion等等
        vector<string> table3{
            "", " Thousand", " Million", " Billion"
        };
        //从低位起，三个数字是一个域，放到vector中
        vector<int> fields;
        while(num > 0){
            int n = num % 1000;
            fields.push_back(n);
            num /= 1000;
        }
        // for(auto c : fields)
        //     cout<<c<<endl;

        //表示有多少个域
        int field = fields.size()-1;
        while(field >= 0){
            int n = fields[field];
            if(n == 0){
                field --;
                continue;
            }
            if(n >= 100){ //百位不等于0
                ret += table1[n/100];
                ret += " Hundred";
            }
            n = n % 100;
            if(n >= 20){
                ret += table2[n / 10];
                ret += table1[n % 10];
            }else{
                ret += table1[n];
            }
            ret += table3[field];
            field--;
        }
        return ret.substr(1);
    }
};

int main(int argc, char const *argv[]) {
    Solution test;
    int n = 101;
    if(argc == 2) n = atoi(argv[1]);
    cout <<"|"<<test.numberToWords(n)<<"|"<<endl;
    return 0;
}
