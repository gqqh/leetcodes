//给一个有序的数组，删除其中有重复的数，保证每一个元素多余的重复值都去掉。
//返回剩余数组的长度

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int l = nums.size();
        for(int i = 1; i < l; i++){
            if(k != 0){ //已经有被删的了，要移动
                if(nums[i] == nums[i-1]){ //该值跟前一个相同，则直接跳过
                    k++;
                }else{
                    nums[i-k] = nums[i];
                }
            }else if(nums[i] == nums[i-1]){ //k == 0 && nums[i] == nums[i-1], 第一个要被删了
                k = 1;
            }
        }
        return l - k;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> t = {1, 1, 2 ,3,3,3,4,5,6,6,6,6,7,7,7,7,78};
    Solution test;
    cout<<test.removeDuplicates(t)<<endl;
    return 0;
}
