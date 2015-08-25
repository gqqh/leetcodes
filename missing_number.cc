//给定一个含有n个不同数字的数组，从0开始，找到其中丢失的一个。
//例如nums = [0, 1, 3] reutrn 2;

//使用二分查找
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        int n = nums.size();
        //前n项和，然后减去，现在的和
        return ((n+1)*n/2 - sum);
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v {1, 2, 3 ,0};
    Solution test;
    cout<<test.missingNumber(v)<<endl;
    return 0;
}
