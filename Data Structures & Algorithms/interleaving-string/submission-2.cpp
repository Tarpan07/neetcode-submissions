class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),m=s3.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1,false));
        if(n1+n2!=m) return false;
        dp[0][0]=true;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                int first = 0;
                int second = 0;
                if (i == 0 && j == 0)
                    continue;

                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};
