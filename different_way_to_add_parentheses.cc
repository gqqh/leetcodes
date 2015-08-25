//给出一个式子，计算所有可能使用括号的运算结果的集合。
// Example 1
// Input: "2-1-1".
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]
//
// Example 2
// Input: "2*3-4*5"
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

//动态规划，每个运算符两边进行递归运算然后再做运算

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        int len = input.size();
        if(len == 0) return ret;
        //处理全部为数字的情况
        int value = 0, index = 0;
        while(index < len && isdigit(input[index])){
            value *= 10;
            value += input[index] - '0';
            index++;
        }
        if(index == len){
            ret.push_back(value);
            return ret;
        }
        for(int i = 0; i < len; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, len));
                // cout<<"ret:[";
                // for(auto c : ret) cout<<c<<" ";
                // cout<<"]"<<endl;
                // cout<<"left:[";
                // for(auto c : left) cout<<c<<" ";
                // cout<<"]"<<endl;
                // cout<<"right:[";
                // for(auto c : right) cout<<c<<" ";
                // cout<<"]"<<endl;
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        switch(input[i]){
                            case '+' : ret.push_back(left[j] + right[k]); break;
                            case '-' : ret.push_back(left[j] - right[k]); break;
                            case '*' : ret.push_back(left[j] * right[k]); break;
                        }//switch
                    }//for
                }//for
            }//if
        }//for
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    string input = "2*3-4*5";
    Solution test;
    vector<int> ret = test.diffWaysToCompute(input);
    for(auto c : ret)
        cout<<c<<endl;
    return 0;
}
