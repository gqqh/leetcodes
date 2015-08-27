//给定一个数组，返回这个数组中除了第i位之外，其他值的乘积
// For example, given [1,2,3,4], return [24,12,8,6].
//不让用除法，时间复杂度为O(n)
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    //使用两个数组f、p，分别表示从前往后和从后往前的乘积，然后求第i个值时，直接
    // f[i]*p[i]
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        if(len <= 1) return ret;
        vector<int> f(len), g(len);
        f[0] = 1;
        for(int i = 1; i < len; i++){
            f[i] = nums[i-1]*f[i-1];
        }
        g[len-1] = 1;
        for(int i = len - 2; i >= 0; i--){
            g[i] = nums[i+1] * g[i+1];
        }
        for(int i = 0; i < len; i++)
            ret.push_back(f[i] * g[i]);

        return ret;
    }*/
    //使用两个数组f、p，分别表示从前往后和从后往前的乘积，然后求第i个值时，直接
    // f[i]*p[i], 时间复杂度为O(n),但是空间复杂度也为O(n)，可以优化一下，
    // 利用返回数组，从左往右遍历依次ret[] == f[]，然后再从右往左遍历回来一遍，
    // 依次使得ret[i] = f[i]*p[i]
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len);
        if(len <= 1) return ret;
        ret[0] = 1;
        for(int i = 1; i < len; i++)
            ret[i] = nums[i-1] * ret[i-1];

        int right = 1;
        for(int i = len-2; i >= 0; i--){
            right *= nums[i+1];
            ret[i] *= right;
        }

        return ret;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v{1,2,3, 4, 5, 8};
    Solution test;
    vector<int> ret = test.productExceptSelf(v);
    for(auto c : ret) cout<<c<<endl;
    return 0;
}
