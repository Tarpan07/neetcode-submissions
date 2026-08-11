class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0] = 1;
        for(int tar=1;tar<=target;tar++){
            int ans = 0;
            for (int num : nums) {
                if (num <= tar) {
                    ans += dp[tar - num];
                }
            }
            dp[tar]=ans;
        }
        return dp[target];
    }
};