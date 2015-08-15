/*
 *Contains Duplicate
 *  Given an array of integers, find if the array contains any duplicates.
 *  Your function should return true if any value appears at least twice in the
 *  array, and it should return false if every element is distinct.
 */
#include <map>
#include <iostream>
#include <vector>

using namespace std;
//把出现过的数都保存在map中，保存的pair是[key=nums[i], value=i]，每次出现一个
//新的数就查看是否在map中，如果在其中,则看value值跟当前值的差是否 <= k，如果
//大于k，则更新nums[i]的value值为当前的i。如果小于等于k，那么返回true。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> int_map;
        map<int, int>::const_iterator it;
        for(int i = 0; i < len; ++i){
          it = int_map.find(nums[i]);
          if(it == int_map.end())
            int_map[nums[i]] = i;
          else if(i - int_map[nums[i]] <= k)
            return true;
          else
            int_map[nums[i]] = i;
        }
        return false;
    }
};
