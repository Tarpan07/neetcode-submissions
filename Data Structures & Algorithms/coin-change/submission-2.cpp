class Solution {
    int getCount(int i, int amount, vector<int>& coins,
                 vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (i < 0)
            return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = 1e9;
        int notTake = 1e9;

        if (coins[i] <= amount) {
            take = 1 + getCount(i, amount - coins[i], coins, dp);
        }

        notTake = getCount(i - 1, amount, coins, dp);

        return dp[i][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amt) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amt + 1, 0));
        for(int i=0;i<n;i++){
            for(int amount=1;amount<=amt;amount++){
                int take = 1e9;
                int notTake = 1e9;

                if (coins[i] <= amount) {
                    take = 1 + getCount(i, amount - coins[i], coins, dp);
                }

                notTake = getCount(i - 1, amount, coins, dp);

                dp[i][amount] = min(take, notTake);
            }
        }
        return dp[n-1][amt]==1e9? -1:dp[n-1][amt];
    }
};