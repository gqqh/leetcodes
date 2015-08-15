//给定一个长度为n的数组，判断是否有a,b,c三个数，使得a+b+c=0.
//返回所有满足要求的三元组
//先对数组进行排序，然后使用两个指针进行遍历，
//三个数的和为0，则必有第一个数 <= 0; 第三个数 >= 0.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
vector<vector<int> > threeSum(vector<int> &num) {
	int len = num.size();
	vector<vector<int> > ret;
	sort(num.begin(), num.end());

    //i用于遍历第一个数
	for(int i = 0; i < len - 2 && num[i] <= 0; i++){
		if(i != 0 && num[i] == num[i-1]) //避免重复
			continue;
        //j用于从i后面从前往后遍历第二个数，k用于从最后往前遍历第三个数
		int j = i + 1, k = len - 1;
		while(j < k && num[k] >= 0){
			if(j != i+1 && num[j] == num[j-1]){
				j++;
				continue;
			}else if(k != len - 1 && num[k] == num[k+1]){
				k--;
				continue;
			}
            //三数之和 == 0
			if(num[j] + num[k] == -num[i]){
				vector<int> tmp{num[i], num[j], num[k]};
				ret.push_back(tmp);
				j++;
				k--;
			}else if(num[j] + num[k] > -num[i])
				k--;
			else
				j++;
		}//end while
	}//end for

	return ret;
}
};
int main(int argc, char const *argv[]) {
	vector<int> v={-1, 0, 1, 2, -1, -4};
	Solution test;
	vector<vector<int> > ret = test.threeSum(v);
	for(auto i : ret){
		for(auto j : i)
			cout<<j<<" ";
		cout <<endl;
	}
	return 0;
}
