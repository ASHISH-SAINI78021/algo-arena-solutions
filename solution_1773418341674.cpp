class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++){
            mini = min(mini, prices[i]);
            maxProfit = max(maxProfit, prices[i] - mini);
        }

        return maxProfit;
    }
};


// prices = 7 1 5 3 6 4