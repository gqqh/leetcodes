//找一个数组中连续一段的和的最大值
//例如[-2,1,-3,4,-1,2,1,-5,4]，的最大值是[4,-1,2,1]，和为6

//使用last标识当前求得的最大值，总是要根以前的最大值比较
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int n = nums.size();
		int last = 0;
		for(int i = 0; i < n; i++){
			if(last <= 0){
				last = nums[i];
			}else{
				last += nums[i];
			}
			max = max > last ? max : last;
		}
		return max;
    }
};
