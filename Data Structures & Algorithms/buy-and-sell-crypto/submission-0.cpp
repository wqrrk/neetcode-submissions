class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; 
        int minBuyValue = prices[0];
        int lt = 0; 
        for (int sellValueIndex = 1; sellValueIndex < prices.size(); sellValueIndex++) { 
            minBuyValue = min(minBuyValue, prices[sellValueIndex - 1]);
            maxProfit = max(maxProfit, prices[sellValueIndex] - minBuyValue);
        } 
        return maxProfit;
    }
};