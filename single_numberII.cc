//给定一个数组所有的数都是有三个值，只有一个数不是的，找出这个数

//使用一个32为的向量，依次记下每个bit位出现的次数，
// 最后，bit位出现次数不为3的整数倍的是例外的那个数的比特位
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitmap(32, 0);

        int len = nums.size();
        for(int i = 0; i < len; i++){
            unsigned int t = nums[i]; //都当做无符号数处理
            int j = 31;
            while(t){
                if(t & 0x01)
                    bitmap[j] ++;
                t >>= 1;
                j--;
            }
        }
        for(auto i:bitmap) cout<<bitmap[i]<<" ";
        cout << endl;
        unsigned int ret = 0;
        for(int i = 0; i < 32; i++){
            ret <<= 1;
            if(bitmap[i] % 3)
                ret += 1;
        }
        return (int)ret;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> v = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    Solution test;
    cout << test.singleNumber(v)<<endl;
    return 0;
}
