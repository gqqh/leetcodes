//merge两个有序的array，成为一个有序的array

//条件比较有意思，nums1有足够的空间放下nums2，并且两个都是有序表，
//我们可以从后面开始比较，把比较大的元素放到适当的位置，直到两个都结束。
//时间复杂的为O(m+n), 空间复杂度为O(1).
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = m + n;
        m -= 1;
        n -= 1;
        t -= 1;
        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[t--] = nums1[m--];
            }else{
                nums1[t--] = nums2[n--];
            }
        }
        while(n >= 0){
            nums1[t--] = nums2[n--];
        }
    }
};
int main(){
    vector<int> s1(100, 0);
    vector<int> s2(10, 0);
    s1[0] = 0;
    int n1 = 0;
    s2[0] = 1;
    int n2 = 1;
    Solution test;
    test.merge(s1, n1, s2, n2);
    for(int i = 0; i < n1+n2; i++)
        cout << s1[i] << endl;
    return 0;
}
