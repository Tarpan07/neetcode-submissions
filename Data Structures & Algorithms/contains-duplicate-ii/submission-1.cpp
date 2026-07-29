class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()) {
                auto it=mpp.find(nums[i]);
                if((i-it->second)<=k) return true;
            }
             mpp[nums[i]]=i;
            
        }
        return false;
    }
};