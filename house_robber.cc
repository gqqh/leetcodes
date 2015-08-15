//给出一个非负的列表，代表可以打劫的收获，但是不能同时打劫相邻两家。
//计算可能的最大收入。
//思想：使用一个数组记录当走到每一家时能获得的最大收获，以及抢劫的最后一家
//是哪一家。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return (max(nums[0], nums[1]));

        vector<int> rets;
        int last = 0;
        rets.push_back(nums[0]);
        if(nums[1] > nums[0]){
            rets.push_back(nums[1]);
            last = 1;
        }else{
            rets.push_back(nums[0]);
        }
        for(int i = 2; i < n; i++){
            if(nums[i] == 0){
                rets.push_back(rets[i-1]);
                continue;
            }
            if(last != i-1){ //上一家没有抢，直接抢了这家
                rets.push_back(rets[last] + nums[i]);
                last = i;
            }else if(rets[i-2] + nums[i] > rets[i-1]){
                rets.push_back(rets[i-2] + nums[i]);
                last = i;
            }else{
                rets.push_back(rets[i-1]);
            }
        }
        return rets[n-1];
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    vector<int> nums = {1,3, 199, 199, 113, 4, 5 ,9};
    // vector<int> nums = {113, 4, 5 ,9};
    cout << test.rob(nums) << endl;
    return 0;
}
