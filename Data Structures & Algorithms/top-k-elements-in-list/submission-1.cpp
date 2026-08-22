class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto &it:mpp){
            int number=it.first;
            int frequency=it.second;
            if(pq.empty())pq.push({frequency,number});
            else{
                auto p=pq.top();
                if(p.first<frequency && pq.size()==k){
                    pq.pop();
                }
                if(pq.size()!=k)pq.push({frequency,number});
            }
        }
        while(!pq.empty()) {
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }   
        return ans;
    }
};
