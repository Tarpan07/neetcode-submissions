class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>ans;
        mpp[nums[0]]=0;
        for(int i=1;i<n;i++){
            int value=nums[i];
            int rest=target-value;
            if(mpp.find(rest)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[rest]);
                break;
            }
            mpp[nums[i]] = i;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
