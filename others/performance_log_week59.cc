//http://hihocoder.com/contest/hiho59/problem/1
//给定一个单线程的运行记录，包含每个函数的启动和结束时间，判定该记录是否错误
//主要错误是1）记录中的时间是不是单调递增的，2）一个函数的结束会不会比开始早，
//3）会不会不对应的start和end
//实际上就是模拟一个函数调用栈
//
// 样例输入
//
//     8
//     FuncA 00:00:01 START
//     FuncB 00:00:02 START
//     FuncC 00:00:03 START
//     FuncC 00:00:04 END
//     FuncB 00:00:05 END
//     FuncD 00:00:06 START
//     FuncD 00:00:07 END
//     FuncA 00:00:08 END
//
// 样例输出
//
//     FuncA 00:00:07
//     FuncB 00:00:03
//     FuncC 00:00:01
//     FuncD 00:00:01
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

struct in_data{
    string func;
    int time;       //将统一表示为秒
    int s_or_e;     //1表示START，0表示END
    in_data():func(""),time(0),s_or_e(true){}
};
int time_to_int(string st){
    if(st.size() != 8) return 0;
    //01:34:67
    if(st[2] != ':' || st[5] != ':') return -1;
    st[2] = '0', st[5] = '0';
    for(int i = 0; i < 8; i++)
        if(!isdigit(st[i]))
            return -1;

    if(st[0] > '2' || (st[0]=='2' && st[1]>'4') ||
        st[3] >= '6' || st[6] >= '6')
        return -1;
    return (((st[0] - '0') * 10 + st[1] - '0') * 3600 +
            ((st[3] - '0') * 10 + st[4] - '0') * 60 +
            ((st[6] - '0') * 10 + st[7] - '0'));
}
string int_to_time(int ti){
    string ret(8, '0');
    if(ti < 0 || ti > 86400) return ret;
    int tmp = ti % 60;
    ret[7] = tmp % 10 + '0';
    ret[6] = tmp / 10 + '0';
    ret[5] = ':';
    ti /= 60;
    tmp = ti % 60;
    ret[4] = tmp % 10 + '0';
    ret[3] = tmp / 10 + '0';
    ret[2] = ':';
    ti /= 60;
    ret[1] = ti % 10 + '0';
    ret[0] = ti / 10 + '0';

    return ret;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    if(n < 2 || n % 2 != 0)
        cout<<"Incorrect performance log"<<endl;

    vector<in_data> in_v;
    vector<in_data> out_v;
    //inputs
    for(int i = 0; i < n; i++){
        in_data tmp;
        string s1, s2;

        cin>>tmp.func>>s1>>s2;
        tmp.time = time_to_int(s1);
        if(s2 == "START")   tmp.s_or_e = 1;
        else if(s2 == "END") tmp.s_or_e = 0;
        else tmp.s_or_e = 2;

        in_v.push_back(tmp);
    }

    pair<int, int> tmp_p;
    //放的是输入向量在vector中的下标以及其调用的order，在out_v中的下标
    stack<pair<int, int> > data_s;
    int order = 0;
    data_s.push(make_pair(0,order++));
    out_v.push_back(in_v[0]);
    for(int i = 1; i < n; i++){
        in_data cur = in_v[i];
        //输入的每个数据先检查其合法性
        if(cur.time < 0 || cur.time < in_v[i-1].time || cur.s_or_e == 3){
            cout<<"Incorrect performance log"<<endl;
            return 0;
        }

        if(cur.s_or_e == 1){ //START入栈
            //入栈检查时间是否正确
            if(!data_s.empty() && in_v[data_s.top().first].time > cur.time){
                cout<<"Incorrect performance log"<<endl;
                return 0;
            }
            data_s.push(make_pair(i, order++));
            out_v.push_back(cur); //同时记录到输出栈，然后后面在修改输出栈中的时间
        }else if(data_s.empty()){ //END出栈
            cout<<"Incorrect performance log"<<endl;
            return 0;
        }else{ //栈不为空，出栈
            pair<int, int> tmp_p = data_s.top();
            data_s.pop();

            in_data last = in_v[tmp_p.first];
            if(cur.func == last.func && cur.time > last.time){
                //修改输出时间
                int o_i = data_s.size()-1;
                out_v[tmp_p.second].time = cur.time - out_v[tmp_p.second].time;
            }else{
                cout<<"Incorrect performance log"<<endl;
                return 0;
            }
        }
    }
    if(!data_s.empty()){
        cout<<"Incorrect performance log"<<endl;
        return 0;
    }
    //输出
    for(auto i : out_v)
        cout<<i.func<<" "<<int_to_time(i.time)<<" "<<endl;

    return 0;
}

/*
struct data{
    string func;
    string time;
    string flag;
    data():func(""),time(""),flag(""){}
};
//根据官方伪代码实现
void performance_log(int n, vector<int> log){
    for(int i = 0; i < n; i++){

    }
}
*/
