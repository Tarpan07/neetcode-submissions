class Solution {
    int getMin(int i,int n,vector<vector<int>>&dp){
        if(n==0) return 0;
        if(i==0) return INT_MAX;
        if(dp[i][n]!=-1) return dp[i][n];
        int take=INT_MAX;
        if(n>=i*i)take=1+getMin(i,n-i*i,dp);
        int notTake=getMin(i-1,n,dp);
        return dp[i][n]=min(take,notTake);
    }
public:
    int numSquares(int n) {
        vector<vector<int>>dp(sqrt(n)+1,vector<int>(n+1,-1));
        return getMin(sqrt(n),n,dp);
    }
};