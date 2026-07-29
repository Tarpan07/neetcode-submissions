class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                if(nums.size()==0) return 0;
        int longest=1;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};
