//实现一个简易的计算器，计算简单的表达式的值
// 表达式中所有数为非负数，只有空格和'+','-'以及括号。

//使用两个栈，一个符号栈，一个数字栈，乘除法当时计数，加减法压栈
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//遇到左括号就把数压入数据栈中，前面一个操作符入栈，遇到运算符就运算，
// 遇到右括号，就出栈一个操作符，和两个操作数，左括号也要入符号栈
class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == ' ') continue;
            if(s[i] == '+' || s[i] == '-' || s[i] == '('){
                op.push(s[i]);
            }else if(isdigit(s[i])){
                int t = s[i++] - '0';
                while(i < len && isdigit(s[i])){
                    t *= 10;
                    t += s[i] - '0';
                    i++;
                }
                if(!isdigit(s[i])) i--; //吐出非数字
                data.push(t);
                calcu();
            }else if(s[i] == ')'){
                op.pop(); //吐出'('
                calcu();
            }else{
                //错误字符
            }
        }//for
        calcu();

        return data.top();
    }
private:
    stack<int> data;
    stack<char> op;
    void calcu(){
        while(!op.empty()){
            if(op.top() == '(') break;
            int r = data.top(); data.pop();
            int l = data.top(); data.pop();
            cout<<l<<" "<<op.top()<<" "<<r<<endl;
            if(op.top() == '+') data.push(l+r);
            else data.push(l-r);
            op.pop();
        }
    }
};
int main(int argc, char const *argv[]) {
    string s="  ((10+4)-(10+ 9)-(4-10) )  ";
    Solution test;
    cout << test.calculate(s)<<endl;
    return 0;
}
