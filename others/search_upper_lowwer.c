#include <stdio.h>

/**
  *二分查找，一个元素，如果存在则返回，否则返回小于其的最大值。
  */
//二分查找，找到元素下标，不存在，返回-1
int find(int *nums, int n, int target){
  // if(n <= 0) return -1;
  // if(nums[0] > target || nums[n-1] < target) return -1;

  int l = 0;
  int u = n-1;
  //[l <= u, nums[l] <= t, nums[u] >= t]
  while(l < u){
    int m = (l + u) / 2;
    if(nums[m] == target) return m;
    else if(nums[m] < target) l = m + 1;
    else u = m - 1;
  }
  //[l == u, nums[l] <= t, nums[u] >= t]
  if(nums[l] == target) return l;
  else return -1;
}
//使用l+1！=u来判断，确保不变式[l+1 < u; nums[l] < t, nums[u] >= t; ]退出条件是
// l + 1 == u
//返回target在nums中的最大下界的下标，不存在时，返回-1
int find_low(int *nums, int n, int target){
  int l = -1;
  int u = n;
  //l+1 <= u, 假设nums[-1] < t <= nums[u]
  while(l + 1 != u){
    int m = (l + u) / 2;
    //确保[l+1<u; nums[l] < t; nums[u] >= t]
    if(nums[m] < target)
      l = m;
    else
      u = m;
  }
  //l+1==u, nums[l] < t; nums[u] >= t
  return l;
}
//同上，只是求最小上界，不存在时返回n
int find_high(int *nums, int n, int target){
  int l = -1;
  int u = n;
  //[l+1 <= u, nums[l] <= t; nums[u] > t]
  while(l + 1 != u){
    int m = (l+u) / 2;
    // 确保[l+1 <= u, nums[l] <= t; nums[u] > t]
    if(nums[m] <= target)
      l = m;
    else
      u = m;
  }
  //[l+1 == u, nums[l] <= t; nums[u] > t]
  return u;
}
int main()
{
    int nums[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 50;
    int t = find(nums, n, target);
    if(t == -1) printf("no find...\n");
    else printf("nums[%d] = %d\n", t, nums[t]);
    int u = find_high(nums, n, target);
    if(u == n) printf("no upper...\n");
    else printf("upper %d : %d\n", target, nums[u]);
    int l = find_low(nums, n, target);
    if(l == -1) printf("no lowwer...\n");
    else printf("lowwer %d : %d\n", target, nums[l]);

    return 0;
}
