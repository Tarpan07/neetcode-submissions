class Solution {
    int getMin(int i,vector<int>&cost,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int onestep=0,twostep=0;
        onestep= cost[i]+ getMin(i-1,cost,dp);
        twostep=cost[i]+getMin(i-2,cost,dp);
        return dp[i]=min(onestep,twostep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(getMin(n-1,cost,dp),getMin(n-2,cost,dp));
    }
};
