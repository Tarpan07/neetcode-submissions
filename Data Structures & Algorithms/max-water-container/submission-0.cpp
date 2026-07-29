class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int maxi=0;
        while(i<j){
            if(heights[i]<heights[j]){
                maxi=max(maxi,heights[i]*(j-i));
                i++;
            }
            else {
                maxi=max(maxi,heights[j]*(j-i));
                j--;
            }
        }
        return maxi;
    }
};
