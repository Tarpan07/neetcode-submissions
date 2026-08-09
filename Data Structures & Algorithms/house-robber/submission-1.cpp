class Solution {
    int getMax(int i,vector<int>& nums,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0, notTake=0;
        take=nums[i]+getMax(i-2,nums,dp);
        notTake=getMax(i-1,nums,dp);
        return dp[i]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return getMax(n-1,nums,dp);
    }
};
