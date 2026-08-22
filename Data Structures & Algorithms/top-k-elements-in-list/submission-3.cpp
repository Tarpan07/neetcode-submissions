class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freq) {
            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int number : bucket[i]) {
                ans.push_back(number);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};