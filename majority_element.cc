//找出一个数组的过半元素，假设数组非空，并且一定有一个元素出现次数超过一半。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        //假设第一个为目标元素
        int ret = num[0];
        int count = 1;

        for(int i = 1, n = num.size(); i < n; i++){
        	if(num[i] == ret)
                count++;
            else{
                count--;
                if(count == 0){
                    //目前没有目标，就让下一个元素为目标值
                    ret = num[++i];
                    count = 1;
                }
            }
        }
        //因为一定存在，所以不用判断了
        return ret;
    }
};

//test
int main(int argc, char const *argv[])
{
	Solution test;
	vector<int> t{1, 2, 0, 3, 2, 4, 2, 2, 5, 2, 6, 2, 2};
	std::vector<int> v{6, 5, 5};
	int r = test.majorityElement(t);
	cout <<r<<endl;
	r = test.majorityElement(v);
	cout <<r<<endl;

	return 0;
}
