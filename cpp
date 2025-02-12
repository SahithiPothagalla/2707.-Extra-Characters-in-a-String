class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n + 1, n);  // Initialize the dp array with a large value
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (const string& word : dictionary) {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = min(dp[i], dp[i - len]);
                }
            }
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }

        return dp[n];
    }
};
