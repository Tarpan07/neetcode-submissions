class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int i = 0, maxCount = 0, maxLen = 0;

        for (int j = 0; j < s.size(); j++) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);

            while ((j - i + 1) - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
