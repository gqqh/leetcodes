//给定一个数组，第i个元素表示第i天股票的价值。
//设计一个算法看看只买入和卖出一次股票最多能赚多少。

//从前到后扫描一次数组，同时记录累次交易的最大收入max和
//当前这笔交易到现在为止的收益fn
//如果今天相对于昨天的净收入，则fn += prices[i] - prices[i-1]，同时更新最大值max
//如果今天相对于昨天赔钱，则计算fn += prices[i] - prices[i-1],如果fn < 0则令fn为0
class Solution {
public:
	/**
	 * f(n) = f(n-1) + A[n]-A[n-1];
	 * f(n) <= 0 ? 0 : f(n);
	 * f(1) = 0;
	 * max = f(n) > max ? f(n) : max;
	 */
     int maxProfit(vector<int> &prices) {
 		int max = 0, fn = 0;
 		int n = prices.size();

 		for(int i = 1; i < n; i++){
 		    int t = prices[i] - prices[i-1];
 		    if(t >= 0){
 			    fn += t;
 			    max = fn > max ? fn : max;
 		    }else if(fn + t > 0){
 		        fn += t;
 		    }else
 		        fn = 0;
 		}

 		return max;
    }
};
