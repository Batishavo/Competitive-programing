class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return dp(s, 0, dict, memo);
    }

private:
    bool dp(const string& s, int pos, const unordered_set<string>& dict, unordered_map<int, bool>& memo) {
        if (pos == s.length()) {
            return true;
        }
        if (memo.find(pos) != memo.end()) {
            return memo[pos];
        }
        for (int i = pos + 1; i <= s.length(); ++i) {
            string word = s.substr(pos, i - pos);
            if (dict.find(word) != dict.end() && dp(s, i, dict, memo)) {
                memo[pos] = true;
                return true;
            }
        }
        memo[pos] = false;
        return false;
    }
};