//从[1,9]中选出k个数，是的这k个数的和等于n
//其中k个数不能有重复，而且每个组合是互异的

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //递归，每次从最大的值开始往下找，思想类似全排列的perm算法，每次尝试之后要pop
    vector<vector<int> > combinationSum3(int k, int n) {
        //45 = 1+2+3+...+9
        if(k > 9 || k < 1 || n < 1 || n > 45) return ret;
        if(k == 1){
            if(n < 10){
                vector<int> t;
                t.push_back(n);
                ret.push_back(t);
            }
            return ret;
        }
        //1 < k <= 9, 1 <= n <= 45
        comb_helper(1, k, n);

        return ret;
    }
private:
    vector<vector<int> > ret;
    vector<int> t;
    //在[i, 9]中找k个数使它们的和为n
    void comb_helper(int i, int k, int n){
        //k == 1 && 1 <= n <= i时终止这次遍历，记录并清零t
        if(k == 1 && i <= n && n <= 9){
            t.push_back(n);
            ret.push_back(t);
            t.pop_back();
            return;
        }else if(k > 1 && n > 0 && i > 0){
            for(int j = i; j < 10; j++){
                t.push_back(j);
                comb_helper(j+1, k-1, n-j);
                //入栈尝试之后，别忘了pop出来，就像perm交换之后要换回来一样
                t.pop_back();
            }
        }
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    int n = 8;
    int k = 2;
    vector<vector<int> > v = test.combinationSum3(k, n);
    for(auto c : v){
        for(auto i : c)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
