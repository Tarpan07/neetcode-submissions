class Solution {
    int getMax(int i,int n,vector<vector<int>>&dp){
        if(i==0)return -1;
        if(n==0) return 1;
        if(dp[i][n]!=-1)return dp[i][n];
        int take=-1;
        if(n-i>=0)take=i*getMax(i,n-i,dp);
        int notTake=getMax(i-1,n,dp);
        return dp[i][n]=max(take,notTake);
    }
public:
    int integerBreak(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return getMax(n-1,n,dp);
    }
};