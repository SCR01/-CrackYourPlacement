class Solution {
public:
    int wordBreak(string A, vector<string> &B) {
        int n = A.length();
        unordered_set<string> dict(B.begin(), B.end());

        // dp[i] represents whether the substring A[0...i] can be segmented
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string can always be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    // If substring A[j...i] is in the dictionary
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }