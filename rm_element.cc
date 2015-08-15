//给一个数组，删除给定的值，并且返回新数组的长度
//记录找到t个值，就把不是该值的数往前移动t个距离

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, l = nums.size();
        for(int i = 0; i < l; i++){
            if(nums[i] != val && k == 0)
                continue;
            else if(nums[i] == val){
                k++;
                continue;
            }else{ //k!=0
                nums[i-k] = nums[i];
            }
        }
        return l-k;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> t = {1,2,3,4,5,6,5,4,5,3,2,1};
    Solution test;
    int n = 5;
    cout<<test.removeElement(t, n) <<endl;
    return 0;
}
