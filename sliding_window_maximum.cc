//给定一个数组，然后给定一个滑动窗口的值k
//窗口每次往右滑动一格，求每次窗口内的最大值
//
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
// Therefore, return the max sliding window as [3,3,5,5,6,7].

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /*
    //使用一个窗口为k的队列，每次直接求队列中的最大值，复杂度为O(k*(n+1-k)),最坏为n^2/4
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ret;
        if(len < 1 || k < 1 || k > len) return ret;

        for(int i = 0; i <= len-k; i++){
            int max = nums[i];
            for(int j = 1; j < k; j++){
                if(nums[i+j] > max)
                    max = nums[i+j];
            }
            ret.push_back(max);
        }

        return ret;
    }*/
    //使用一个窗口为k的队列，每次记录最大值与其下标，
    // 如果还在窗口内，则直接比较新值与最大值的关系
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ret;
        if(len < 1 || k < 1 || k > len) return ret;
        int max = 0;
        for(int i = 1; i < k; i++){
            if(nums[i] > nums[max])
                max = i;
        }
        ret.push_back(nums[max]);
        for(int i = k; i < len; i++){
            //最大值还在窗口内
            if(nums[i] >= nums[max]){ //新入的是最大值
                max = i;
            }else if(max <= i-k){ //新入的不是最大值，而且最大值也不在区间
                max = i-k+1;
                for(int j = max+1; j <= i; j++){
                    if(nums[j] > nums[max]) max = j;
                }
            }

            ret.push_back(nums[max]);
        }

        return ret;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v{1,-1};//{1,3,-1,-3,5,3,6,7};
    int k = 1;
    Solution test;
    vector<int> ret = test.maxSlidingWindow(v, k);
    for(auto i : ret) cout<<i<<endl;
    return 0;
}
