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
//思想是把出现过得值都保存在map中，pair为[nums[i], 0],key值为nums的值，value随意，
//注意，后面一个例子需要用到value来保存nums[i]出现的下标i，如果某个值在map中，即
//map.find(nums[i]) != map.end();则返回true
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        map<int, int> int_map;
        map<int, int>::const_iterator it;
        for(int i = 0; i < len; ++i){
          it = int_map.find(nums[i]);
          if(it == int_map.end())
            int_map[nums[i]] = 0;
          else
            return true;
        }
        return false;
    }
};
