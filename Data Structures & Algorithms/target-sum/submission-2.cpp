class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(),0);
        if(abs(target)>totalsum)    return 0;
        if((target + totalsum)%2 == 1)  return 0;
        int P = (target+totalsum)/2;
        vector<vector<int>>dp(n, vector<int>(P+1,0));
        if(nums[0]==0)  dp[0][0] = 2;
        else    dp[0][0] = 1;

        if(nums[0]!=0 && nums[0]<=P){
            dp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=P;j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][P];
    }
};