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
        for(auto &it : mpp) {
            int number = it.first;
            int frequency = it.second;

            pq.push({frequency, number});

            if(pq.size() > k) {
                pq.pop();
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
