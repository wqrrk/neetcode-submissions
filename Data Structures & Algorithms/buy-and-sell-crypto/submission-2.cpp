class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyValue = prices[0]; 
        int maxSellValue = 0; 

        for (int sellValueIndex = 1; sellValueIndex < prices.size(); sellValueIndex++) { 
            minBuyValue = min(minBuyValue, prices[sellValueIndex - 1]);
            maxSellValue = max(maxSellValue, prices[sellValueIndex] - minBuyValue);
        }
        return maxSellValue;
    }
};