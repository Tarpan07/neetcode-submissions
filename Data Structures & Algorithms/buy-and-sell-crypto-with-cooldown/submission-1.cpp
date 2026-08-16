class Solution {
int func(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>&dp){
    if (ind >= n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit=0;
    if (buy == 0) { 
            profit = max(0 + func(ind + 1,0,n,prices,dp), (-1)*prices[ind] + func(ind + 1,1,n,prices,dp));
        }

    if (buy == 1) { 
        profit = max(0 + func(ind + 1,1,n,prices,dp), prices[ind]+ func(ind + 2,0,n,prices,dp));
    }
    return  dp[ind][buy] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,0,n,prices,dp);
    }
};