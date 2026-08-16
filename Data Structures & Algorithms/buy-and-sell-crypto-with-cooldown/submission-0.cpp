class Solution {
    int getMax(int i, int buy, vector<int>& prices,vector<vector<int>>&dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy) {
            int take = -prices[i] + getMax(i + 1, 0, prices,dp);
            int pass = getMax(i + 1, 1, prices,dp);

            return dp[i][buy]=max(take, pass);
        }
        else {
            int sell = prices[i] + getMax(i + 2, 1, prices,dp);
            int pass = getMax(i + 1, 0, prices,dp);

            return dp[i][buy]=max(sell, pass);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return getMax(0, 1, prices,dp);
    }
};