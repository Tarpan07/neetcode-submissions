class Solution {
public:
    int numSquares(int n) {
        vector<vector<int>>dp(sqrt(n)+1,vector<int>(n+1,1e9));
        for(int i=0;i<=sqrt(n);i++)dp[i][0]=0;
        for(int i=1;i<=sqrt(n);i++){
            for(int j=1;j<=n;j++){
                int take=INT_MAX;
                if(j>=i*i)take=1+dp[i][j-i*i];
                int notTake=dp[i-1][j];
                 dp[i][j]=min(take,notTake);
            }
        }
        return dp[sqrt(n)][n];
    }
};