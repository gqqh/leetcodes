//给一个大小为n的数组，找其中出现次数超过n/3的元素

//考虑到每个元素要超过n/3所以，最多也就两个这样的元素。
//类似与找超过半数的元素一样，假设前两个不同的元素分别是，则统计其次数，
// 如果后面的数跟其中的某个相同，则计数加1，否则，两个数都减1
// 然后还要在再判断这两个是否都是超过n/3，所以还要再统计这两个数的次数
// 找超过n/2的数时，因为只有一个，所以只要有，肯定是最多值。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        if(len < 1) return ret;
        int n1 = 0, n2 = 0;
        int cn1 = 0, cn2 = 0;
        //找出出现次数最多的两个数
        //如果与某一个数相等，则加1，都不等如果某一个为0则把该数设为n,其次数为1
        // 否则都减1
        for(int i = 0; i < len; i++){
            if(nums[i] == n1) cn1++;
            else if(nums[i] == n2) cn2++;
            else if(cn1 == 0){
                n1 = nums[i];
                cn1 = 1;
            }else if(cn2 == 0){
                n2 = nums[i];
                cn2 = 1;
            }else{
                cn1--;
                cn2--;
            }
        }
        //判断这两个数都超过n/3
        cn1 = cn2 = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == n1) cn1++;
            else if(nums[i] == n2) cn2++;
        }
        if(cn1 > len / 3) ret.push_back(n1);
        if(cn2 > len / 3) ret.push_back(n2);

        return ret;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v{1,3,5,3, 1};
    Solution test;
    vector<int> ret = test.majorityElement(v);
    for(auto i : ret) cout<<i<<endl;
    return 0;
}
