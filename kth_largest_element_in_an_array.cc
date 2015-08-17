//找一个数列中的第k大
//可以使用快速排序的思想

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
//方法一、使用选择排序的思想，在k比较小时，效率较高O(k*n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //1 <= k <= nums.size()
        int len = nums.size();
        if(len < 1 || k < 1 || k > len) return -1;

        for(int i = 0; i < k; i++){
            int max = i;
            int j;
            for(j = i; j < len; j++)
                if(nums[j] > nums[max]) max = j;
            swap(nums[i], nums[max]);
        }
        return nums[k-1];
    }
};
*/
//方法二、使用快速排序的思想
// 一次快排，找到划分点p = find(nums, 0, n-1, k)
// if(p == k-1) return nums[p]
// else if(p < k-1), 迭代找find(nums, p+1, n-1, k-p-1)
// else 迭代找find(nums, 0, p, k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //1 <= k <= nums.size()
        int len = nums.size();
        if(len < 1 || k < 1 || k > len) return -1;

        return find(nums, 0, len-1, k);
    }
private:
    //在nums[b, ..., e]中找第k大元素
    int find(vector<int>& nums, int b, int e, int k){
        int p = nums[b];
        int old_b = b, old_e = e;
        while(b < e){
            while(b < e && nums[e] <= p) e--;
            nums[b] = nums[e];
            while(b < e && nums[b] >= p) b++;
            nums[e] = nums[b];
        }
        nums[b] = p;
        for(auto i : nums) cout<<i<<" ";
        cout <<endl;
        cout<<b<<"|"<<nums[b]<<endl;
        if(b == k-1) return nums[b];
        else if(b < k-1) return find(nums, b+1, old_e, k);
        else return find(nums, old_b, b, k);
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    vector<int> v{3,1,2,5,6,4};
    int k = 2;
    cout<<test.findKthLargest(v, k)<<endl;

    return 0;
}
