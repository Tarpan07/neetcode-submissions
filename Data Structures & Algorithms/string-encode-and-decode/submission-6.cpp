class Solution {
public:
    // Encode: prefix each string with its length + '#'
    string encode(vector<string>& strs) {
        string s;
        for (auto &str : strs) {
            s += to_string(str.size()) + "#" + str;
        }
        return s;
    }

    // Decode: read each length, extract substring accordingly
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // find '#'
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i)); // extract length
            string word = s.substr(j + 1, len);
            ans.push_back(word);
            i = j + 1 + len; // move past this word
        }
        return ans;
    }
};
