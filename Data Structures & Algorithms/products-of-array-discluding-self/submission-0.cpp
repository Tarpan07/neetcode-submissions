class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)product=product*nums[i];
            else cnt++;
        }
        vector<int>ans(n,product);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(cnt>1){
                      ans[i]=0;
                }
                else  {
                    ans[i]=product;
                }
            } 
            else if(!cnt)ans[i]=(ans[i]/nums[i]);
            else ans[i]=0;
        }
        return ans;

    }
};
