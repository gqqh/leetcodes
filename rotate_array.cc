//把一个长为n的数组的右边k个数放到最左边。
//n = 7, k = 3; nums=[1,2,3,4,5,6,7] --> nums=[5,6,7,1,2,3,4]
//这一题有多种方法
//蛮力就是直接找个备份数组，前面一部分放到后面，把后面k个放到前面。
//也可以依次将右边的数放到正确的位置，每次的跳数为k
//经典的就是旋转的方法，[ab]' = [a'b'] = ba
#include <iostream>
#include <vector>
using namespace std;
/*
//直接使用额外数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k <= 0 || n <= 1) return;
        vector<int> t;
        for(int i = n-k; i < n; i++)
            t.push_back(nums[i]);
        for(int i = 0; i < n-k; ++i)
            t.push_back(nums[i]);
        nums = t;
    }
};
*/

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k <= 0 || n <= 1) return;
        rotate_h(nums, 0, n-k-1);
        rotate_h(nums, n-k, n-1);
        rotate_h(nums, 0, n-1);
    }
private:
    void rotate_h(vector<int>& n, int b, int e){
        if(b < 0 || e < 0 || b >= e) return;
        int mid = (e - b) / 2;
        for(int i = 0; i <= mid; ++i)
            swap_t(n, b+i, e-i);
    }
    void swap_t(vector<int>& n, int a, int b){
        int tmp = n[a];
        n[a] = n[b];
        n[b] = tmp;
    }
};
*/
int main(int argc, char const *argv[]) {
    Solution test;
    vector<int> nums={1, 2, 3 ,4 ,5, 6, 7};
    int k = 3;
    test.rotate(nums, k);
    for(auto i : nums)
        cout<<i<<endl;
    return 0;
}
