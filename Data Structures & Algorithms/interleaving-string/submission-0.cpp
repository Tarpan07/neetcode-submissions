class Solution {
    bool check(int i, int j, string &s1, string &s2, string &s3,vector<vector<int>>&dp) {
        if (i < 0 && j < 0)
            return 1;
        if(dp[i+1][j+1] != -1)
            return dp[i+1][j+1];
        int first = 0;
        int second = 0;
        if (i >= 0 && s1[i] == s3[i + j + 1]) {
            first = check(i - 1, j, s1, s2, s3,dp);
        }
        if (j >= 0 && s2[j] == s3[i + j + 1]) {
            second = check(i, j - 1, s1, s2, s3,dp);
        }
        return dp[i+1][j+1] = first || second;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),m=s3.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        if(n1+n2!=m) return false;
        return check(n1-1,n2-1,s1,s2,s3,dp)==1? true: false;
    }
};
