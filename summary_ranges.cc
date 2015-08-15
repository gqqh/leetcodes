#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 *  Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 *  For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
 */

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums){
		vector<string> ret;
		int len = nums.size();
		int begin = 0, end = 0;
		for(int i = 0; i < len; ){
			begin = i;
			end = begin + 1;
			while(end < len && nums[end] == nums[end-1] + 1)
				end++;
			if(begin +1 == end)
				ret.push_back(to_string(nums[begin]));
			else
				ret.push_back(to_string(nums[begin]) + "->" + to_string(nums[end-1]));
			
			i = end;
		}
		return ret;
	}
};

int main()
{
	Solution test;
	vector<int> nums = {0, 1, 2, 4, 5, 7};
	vector<string> ret = test.summaryRanges(nums);
	for(auto s : ret)
		cout<<s<<endl;

	return 0;
}
