//给一个整型的数组，找出是否有两个不同的下标i,j是的abs(i, j) <= k,
// 并且abs(nums[i], nums[j]) <= t

#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;

class Solution {
public:
    /*
    //维持一个k+1大小的窗口，每次向右移动窗口时，依次判断, j-i <= k
    //时间复杂度O(kn)，TLE
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        t = t < 0 ? -1 * t : t;
        if(k < 0 || len < 1) return false;
        for(int i = 1; i < len && i < k; i++){
            for(int j = 0; j < i; j++){
                if(abs(nums[i] - nums[j]) <= t)
                    return true;
            }
        }
        for(int i = k; i < len; i++){
            for(int j = i-k; j < i; j++){
                if(abs(nums[i] - nums[j]) <= t)
                    return true;
            }
        }
        return false;
    }
    */
    /*
    //维持一个大小为k的，multiset，然后每次插入一个数时，
    // 找它的upper_bound和lower_bound，如果两个不相等，则返回true，
    // 否则踢出最开始进入的那个元素，并且加入当前元素
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if(k <= 0 || len < 1 || t < 0) return false;
        multiset<long long int> mset;
        multiset<long long int>::iterator itb, ite;
        mset.insert(nums[0]);
        long long int tt = t;
        for(int i = 1; i < len; i++){
            // [nums[i] - t, nums[i]+t ]范围内有元素，则返回true
            itb = mset.lower_bound(nums[i] - tt); // >= nums[i]-t
            ite = mset.upper_bound(nums[i] + tt); // > nums[i] + t
            // if(itb == mset.end()) cout<<"itb"<<endl;
            // else cout<<*itb<<endl;
            // if(ite == mset.end()) cout<<"ite"<<endl;
            // else cout<<*ite<<endl;
            if(itb != ite) return true;
            if(i >= k){ //维持窗口大小为k
                mset.erase(mset.find(nums[i-k]));
            }
            mset.insert(nums[i]);
        }

        return false;
    }
    */
    //上面找两次好像有点多余，可以减少一次
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if(k <= 0 || len < 1 || t < 0) return false;
        multiset<long long int> mset;
        multiset<long long int>::iterator itb, ite;
        mset.insert(nums[0]);
        long long int tt = t;
        for(int i = 1; i < len; i++){
            // 找到[nums[i] - t, mset.end())，只要看最开始的一个就可以
            itb = mset.lower_bound(nums[i] - tt); // >= nums[i]-t
            if(itb != mset.end() && *itb <= nums[i]+tt) return true;
            if(i >= k){ //维持窗口大小为k
                mset.erase(mset.find(nums[i-k]));
            }
            mset.insert(nums[i]);
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v{0, 2147483647};
    Solution test;
    int k = 1;
    int t = 2147483647;
    cout << test.containsNearbyAlmostDuplicate(v, k, t)<<endl;
    return 0;
}
