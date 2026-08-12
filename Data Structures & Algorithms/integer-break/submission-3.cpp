class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int take=-1;
                if(j-i>=0)take=i*dp[i][j-i];
                int notTake=dp[i-1][j];
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[n-1][n];
    }
};