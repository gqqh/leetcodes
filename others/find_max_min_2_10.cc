//找一个数组中的最大值和最小值

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//方法一、蛮力是从前遍历，比较2n次
//略

//方法二、一般而言，最大值和最小值不会是同一个数，除非只有一个数或者所有数都相等
//则可以相邻的两个进行比较，把较大的数放在偶数位，然后分别在奇数位找最小值，
// 在偶数为找最大值
//同时使用一个小技巧，如果数组长度为奇数，则强行插入一个哨岗，即a[n] = a[n-1]
//只比较了1.5*N

void find_max_min(vector<int> nums){
    int len = nums.size();
    if(len <= 0) return;
    if(len % 2 == 1){
        nums.push_back(nums[len-1]);
        len++;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < len; i += 2){
        if(nums[i] < nums[i+1]){
            if(nums[i] < min){
                min = nums[i];
            }
            if(nums[i+1] > max){
                max = nums[i+1];
            }
        }else{ //nums[i] >= nums[i+1]
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i+1] < min){
                min = nums[i+1];
            }
        }
    }

    cout<<"max : " << max << endl << "min : "<<min<<endl;
}

int main(int argc, char const *argv[]) {
    vector<int> v{6, 5, 3, 5, 1, 2, 4, 9, 2};
    find_max_min(v);
    return 0;
}
