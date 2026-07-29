class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int sum=0,cnt=0;
        int i=0,j=n-1;
        while(i<=j){
            sum=people[i]+people[j];
            if(sum>limit){
                j--;
            }
            else{
                i++;j--;
            }
            cnt++;
        }

        return cnt;
    }
};