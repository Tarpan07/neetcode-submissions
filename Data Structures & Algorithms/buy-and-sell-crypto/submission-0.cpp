class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,n=prices.size();
        int profit=0,buy=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
                continue;
            }
            else profit=max(profit,prices[i]-buy);
        }
        return profit;
    }
};
