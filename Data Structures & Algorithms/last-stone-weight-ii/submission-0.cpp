class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int total = 0;
        for (int x : stones) {
            total += x;
        }
        int target = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {

                dp[i][j] = dp[i - 1][j];

                if (stones[i - 1] <= j) {
                    dp[i][j] = dp[i][j] ||
                               dp[i - 1][j - stones[i - 1]];
                }
            }
        }

        int s1 = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[n][j]) {
                s1 = j;
                break;
            }
        }

        int s2 = total - s1;

        return s2 - s1;
    }
};