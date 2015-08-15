//爬一个长度为n的楼梯，每次可以走一步或者两步，求出有多少中爬法

//典型的一个动态规划的题目，使用一个备忘录记录前面的数据
//f(n) = f(n-1) + f(n-2);
//f(1) = 1, f(2) = 2;
class Solution {
public:
	/*超时！！！TLE
    int climbStairs(int n){
	if(n < 3) return n;
	int last1 = 1, last2 = 2;
	int ret;
	for(int i = 3; i <= n; i++){
		ret = last1 + last2;
		last1 = last2;;
		last2 = ret;
	}
	return ret;
}*/
//动态规划，f(n) = f(n-1)+f(n-2);f(1)=1,f(2)=2;
	int climbStairs(int n) {
		if (n < 3)	return n;
		int last1 = 1, int last2 = 2;

		//每次计算两步长！！
		for (int i = 3; i <= n; i+=2){
			last1 += last2;
			last2 += last1;
		}

		if(n % 2)
			return last1;
		return last2;
	}
};
