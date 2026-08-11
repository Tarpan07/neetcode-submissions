class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1; i >= 0; i--) {
            for(int prevInd = i-1; prevInd >= -1; prevInd--) {
                int notTake = dp[i+1][prevInd+1];
                int take = 0;
                
                if(prevInd == -1 || nums[i] > nums[prevInd]) {
                    take = dp[i+1][i+1] + 1;
                }
                dp[i][prevInd+1] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }
};