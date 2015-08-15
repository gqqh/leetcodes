//也是给一个数组，第i个值表示第i天的股票价值，允许多次买入和卖出股票，
//计算最大收益值。

//多次低价买入高价卖出，同样使用记录当前交易的收入fn，
//如果prices[i+1] >= prices[i],就持有，反之则卖出,同时，买入prices[i+1],置fn=0.
class Solution {
public:
	int maxProfit(vector<int> &prices) {
        int profit = 0;
        int size = prices.size();
        if(size <= 1)    return profit;

        int fn = 0;
        for(int i = 1; i < size; i++){
        	int t = prices[i] - prices[i-1];
            if(t > 0) fn += t;
            else{
                profit += fn;
                fn = 0;
            }
        }
        return profit + fn;
    }
};
