//等概率随机数函数，编程珠玑中第十二章研究的问题

//在[0, 1, ..., n-1]中，产生m(0 < m < n)个随机数，升序
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

//在[0, 1, ..., n-1]中，产生m(0 < m < n)个随机数，升序
//可以证明，最终返回的m个数是等概率随机的
//该算法时间复杂度为O(n)
vector<int> gen_knuth(int m, int n){
    vector<int> ret;
    srand(time(0)); //使用当前时间作为随机数种子
    for(int i = 0; i < n && m > 0; i++){
        if((rand() % (n-i)) < m){
            ret.push_back(i); //每个元素被产生的概率都是m/n
            // cout << i << endl;
            m--;
        }
    }
    return ret;
}
//产生一个集合，把生成的随机数放到这个集合中
//随机生成数[0, ..., n-1]，然后看看是不是在集合中，如果不在就插入
//效率比上一个要高，时间复杂度为O(m)
//但是，当m接近与n时，效果极差
set<int> gen_set(int m, int n){
    set<int> ret;
    srand(time(0));
    while(ret.size() < m){
        ret.insert(rand() % n);
    }

    return ret;
}
//还有一个方法是，把数组[0,...,n-1]的前面m个数打乱，然后，把前面m个数排序输出。
//时间复杂度，依赖于m，O(m + mlogm)
vector<int> gen_shuf(int m, int n){
    vector<int> ret(n);
    //初始化
    for(int i = 0; i < n; ++i)
        ret[i] = i;
    //随机交换
    srand(time(0));
    for(int i = 0; i < m; ++i)
        swap(ret[i], ret[rand()%(n-i)]);

    //排序输出前面m个
    ret.resize(m);
    sort(ret.begin(), ret.begin()+m);

    return ret;
}
//针对上一个算法，floyd优化了一个，不依赖于m的
set<int> gen_floyd(int m, int n){
    set<int> ret;
    srand(time(0));
    for(int i = n - m; i < n; i++){
        int t = rand() % (i + 1);
        if(ret.find(t) == ret.end())
            ret.insert(t); //t不在，则插入t
        else //t在，则意味着t在i小于当前i时就已经插入了，意味着t != i，所以i插入也是正确的
            ret.insert(i);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    vector<int> r;
    int n = 1000;
    int m = 4;
    if(argc == 3){
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    // r = gen_knuth(m, n);
    // cout << "rand" << endl;
    // for(auto i : r) cout << i << endl;

    // set<int> s = gen_set(m, n);
    // cout << "set" << endl;
    // for(auto i : s) cout << i << endl;

    // vector<int> v = gen_shuf(m, n);
    // cout << "shuf" << endl;
    // for(auto i : v) cout << i << endl;

    set<int> f = gen_floyd(m, n);
    cout << "floyd" << endl;
    // for(auto i : f) cout << i << endl;
    return 0;
}
