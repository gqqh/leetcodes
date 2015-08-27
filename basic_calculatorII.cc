//实现一个简易的计算器，计算简单的表达式的值
// 表达式中所有数为非负数，只有空格和'+','-','*','/'。

//使用两个栈，一个符号栈，一个数字栈，乘除法当时计数，加减法压栈
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
/*
    //乘除法不入栈，所以每次遇到'+/-'时，
    // 如果符号栈中有符号，就处理掉，否则压栈，这样以来，符号栈中最多就一个符号，
    // 而数据栈中最多就两个数字，所以取消符号栈，用char代替，
    // 取消数据栈用n1,n2代替
    //太慢了
    int calculate(string s) {
        int len = s.size();
        if(len < 1) return 0;
        char op = 0;
        int n1, n2;
        int i = 0;
        n1 = stoi(s);
        while(i < len && isdigit(s[i])) i++;
        i--;
        for(; i < len; i++){
            // cout<<s[i]<<endl;
            if(s[i] == ' ') continue;
            if(s[i] == '+' || s[i] == '-'){
                // cout<<"op"<<op<<endl;
                if(op != 0){ //把之前的运算结束掉
                    // cout<<n1<<" "<<op<<" "<<n2<<endl;
                    if(op == '+') n1 += n2;
                    else n1 -= n2;
                    op = s[i++];
                    n2 = stoi(s.substr(i));
                    while(i < len && isdigit(s[i])) i++;
                    i--;
                }else{ //op == 0, 记录n1, n2
                    op = s[i++];
                    n2 = stoi(s.substr(i));
                    while(i < len && isdigit(s[i])) i++;
                    i--;
                    // cout<<op<<"|"<<n1<<"|"<<n2<<endl;
                }
            }else if(s[i] == '*' || s[i] == '/'){
                char oper = s[i++]; //记录下操作符
                int t = stoi(s.substr(i));
                while(i < len && isdigit(s[i])) i++;
                i--;
                // if(oper == '/' && t == 0) return 0; //除数为0
                if(op == 0){ //处理n1 op 后面一个数
                    // cout<<n1<<" "<<oper<<" "<<t<<endl;
                    if(oper == '*') n1 *= t;
                    else n1 /= t;
                }else{ //处理n2 op 后面一个数
                    // cout<<n2<<" "<<oper<<" "<<t<<endl;
                    if(oper == '*') n2 *= t;
                    else n2 /= t;
                }//op != 0
            }//'*','/'
        }//for
        // cout<<n1<<"|"<<op<<"|"<<n2<<endl;
        if(op != 0){
            if(op == '+') n1 += n2;
            else n1 -= n2;
        }
        return n1;
    }
    */
    
    // 下面使用istringstream来处理输入数据，解决输入数据解析的耗时，
    // 然后思想没变，用op当做操作符栈，因为最多有一个操作符缓存，栈空记为op=0;
    // 使用n1和n2当做操作数栈，因为最多只有两个操作数缓存，起始先把一个数放到n1
    // 如果当前运算符是'+'和'-',则把之前的运算给处理了，
    // 把处理结果放到n1，然后记录当前的操作符；如果当前运算符是'*'和'/'，
    // 则直接在栈顶运算，此时要注意运算符栈还没有有值如果有，
    // 则用n2和后面的数运算，否则用n1和后面的数运算

    int calculate(string s) {
        if(s.empty()) return 0;
        istringstream sin(s);
        char op = 0, cop;
        int n1, n2;
        sin >> n1; //第一个操作数
        while(sin >> cop){ //当前操作符
            if(cop == '+' || cop == '-'){ //'+','-'
                if(op != 0){ //把之前的运算结束掉
                    // cout<<n1<<" "<<op<<" "<<n2<<endl;
                    if(op == '+') n1 += n2;
                    else n1 -= n2;
                    op = cop;
                    sin >> n2;
                }else{ //op == 0, 记录cop, n2
                    op = cop;
                    sin >> n2;
                    // cout<<op<<"|"<<n1<<"|"<<n2<<endl;
                }
            }else if(cop == '*' || cop == '/'){ //'*', '/'不如栈
                int t; //下一个操作数
                sin >> t;
                // if(oper == '/' && t == 0) return 0; //除数为0
                if(op == 0){ //处理n1 op 后面一个数
                    // cout<<n1<<" "<<oper<<" "<<t<<endl;
                    if(cop == '*') n1 *= t;
                    else n1 /= t;
                }else{ //处理n2 op 后面一个数
                    // cout<<n2<<" "<<oper<<" "<<t<<endl;
                    if(cop == '*') n2 *= t;
                    else n2 /= t;
                }//op != 0
            }
        }
        // cout<<n1<<"|"<<op<<"|"<<n2<<endl;
        if(op != 0){
            if(op == '+') n1 += n2;
            else n1 -= n2;
        }
        return n1;
    }

};
int main(int argc, char const *argv[]) {
    string s="  10+4-10 +9*2*3-7*3/2- 4 - 4 - 1 + 1+2+3+4+5  ";
    Solution test;
    cout << test.calculate(s)<<endl;
    return 0;
}
