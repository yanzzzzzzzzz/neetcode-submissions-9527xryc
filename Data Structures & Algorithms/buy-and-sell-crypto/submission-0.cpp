class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //暴力解, 2層for迴圈
        int maxPrice = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                int price = prices[j] - prices[i];
                maxPrice = max(price, maxPrice);
            }
        }
        return maxPrice;
    }
};
