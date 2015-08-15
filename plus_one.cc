//一个非负数，每一位都保存在vector中，然后+1

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc = 1;
        int l = digits.size();
        vector<int> ret(l, 0);
        for(--l; l >= 0; --l){
            int t = acc + digits[l];
            if(t > 9){
                acc = 1;
                ret[l] = t - 10;
            }else{
                acc = 0;
                ret[l] = t;
            }
        }
        if(acc){
            ret.push_back(acc);
            for(int l = ret.size(); l > 0; --l )
                ret[l] = ret[l-1];
            ret[0] = acc;
        }

        return ret;
    }
};
int main(int argc, char const *argv[]) {
    vector<int> t = {9,9,0,9};
    Solution test;
    vector<int> r = test.plusOne(t);
    for(auto c : r){
        cout << c << endl;
    }
    return 0;
}
