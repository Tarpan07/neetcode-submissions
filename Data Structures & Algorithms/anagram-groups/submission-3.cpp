class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mpp;
        vector<int> hash(26,0);
        vector<vector<string>>ans;
        int n=strs.size();
        for(int i=0;i<n;i++){
            int m=strs[i].size();
            vector<int> hash(26,0);
            for(int j=0;j<m;j++)hash[strs[i][j]-'a']++;
            mpp[hash].push_back(strs[i]);
        }
        for(auto &it: mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
