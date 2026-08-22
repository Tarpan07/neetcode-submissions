class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<int> hash(26,0);
        vector<vector<string>>ans;
        int n=strs.size();
        for(int i=0;i<n;i++){
            int m=strs[i].size();
            vector<int> hash(26,0);
            for(int j=0;j<m;j++)hash[strs[i][j]-'a']++;
            string s="";
            for(int k=0;k<26;k++)s += to_string(hash[k]) + "#";
            mpp[s].push_back(strs[i]);
        }
        for(auto &it: mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
