//给定一个数组，其中所有的数都出现两次，除了其中的两个数，找到这两个数

//方法一，可以利用集合的互异性，如果存在则删除，最后剩下的两个就是

#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> a_set;
        for(auto i : nums){
            if(!a_set.insert(i).second){
                a_set.erase(i);
            }
        }
        vector<int> ret;
        if(a_set.size() != 2) return ret;
        for(set<int>::iterator b = a_set.begin(), e = a_set.end();
                b != e; ++b)
                ret.push_back(*b);

        return ret;
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    vector<int> v{2,1,1,2,3,5};
    vector<int> t = test.singleNumber(v);
    for(auto i : t) cout<<i<<endl;
    return 0;
}
