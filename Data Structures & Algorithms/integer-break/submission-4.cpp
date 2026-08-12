class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i < j; i++) {
                dp[j] = max(dp[j], i * max(j - i, dp[j - i]));
            }
        }
        return dp[n];
    }
};