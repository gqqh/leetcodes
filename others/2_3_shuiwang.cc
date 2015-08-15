//找一个数组中，超过半数的那个数，假设这个数一定存在
//每次丢弃两个不同的数，最后剩下的一定是那个超过半数的数，
//如果相同，则记录有多少个该数据
//也可以进行排序，然后返回array[(n+1)/2]

#include <iostream>
#include <vector>

using namespace std;

//找水帖之王

int func(vector<int> t){
    if(t.size() == 0) return -1;
    int count = 1;
    int ret = t[0];
    for(int i = 1, size = t.size(); i < size; i++){
        if(t[i] == ret){
            count ++;
            continue;
        }else{
            count--;
            if(count == 0){ //当备选的水王次数少于1时，一定不会结束
                ret = t[i];
                count = 1;
            }
        }
    }
    return ret;
}
/*
//找超级水王，有3个ID，它们每个ID都超过1/4，找出这三个ID
//思路也是，有三个备选，3个计数器。
vector<int> super(vector<int> t){
    vector<int> ret(3, -1);
    if(t.size() < 3)
        return ret;
    vector<int> count(3,0);

    //初始化ret[0..2], count[0..2]
    ret[0] = t[0];
    count[0] = 1;
    int i = 1, l = t.size();
    for(int j = 1; j < 3; i++){
        if(t[i] == ret[0])  count[0]++;
        else if(t[i] == ret[1]) count[1]++;
        else if(t[i] == ret[2]) count[2]++;
        else{
            ret[j] = t[i];
            count[j] = 1;
            j++;
        }
    }
    cout<<ret[0]<<"|"<<count[0]<<endl;
    cout<<ret[1]<<"|"<<count[1]<<endl;
    cout<<ret[2]<<"|"<<count[2]<<endl;

    for(int l = t.size(); i < l; ++i){
        cout<<"\ni = "<<i<<"|"<<t[i]<<endl;
        bool flag = false; //是否是一个水王
        for(int j = 0; j < 3; j++){
            if(t[i] == ret[j]){ //是水王，则计数+1
                count[j]++;
                flag = true;
                break;
            }
        }
        if(flag == false){ //不是水王
        //error
            // for(int j = 0; j < 3; j++){
            //     count[j]--;
            //     if(count[j] == 0){
            //         int o1 = (j+1)%3, o2 = (j+2)%3;
            //         while(t[i] == ret[o1] || t[i] == ret[o2]){
            //             if(t[i] == ret[o1]){
            //                 count[o1]++;
            //             }else{
            //                 count[o2]++;
            //             }
            //             i++;
            //         }
            //         ret[j] = t[i];
            //         count[j] = 1;
            //     }
            // }
        }
        cout<<ret[0]<<"|"<<count[0]<<endl;
        cout<<ret[1]<<"|"<<count[1]<<endl;
        cout<<ret[2]<<"|"<<count[2]<<endl;
    }

    return ret;
}
*/
int main(){
    vector<int> t = {3, 2, 3 ,4 ,1, 2, 3, 3, 4};
    vector<int> t1 = {3, 3, 3 ,4 ,1, 4, 2, 3, 4, 3, 6, 4, 2, 9, 4, 2, 2, 1, 2};
    cout<<func(t)<<endl;
    std::vector<int> v = super(t1);
    for(int i = 0 ; i < 3; ++i)
        cout<<v[i]<<endl;

    return 0;
}
