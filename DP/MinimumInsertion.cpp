class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        // int ans=0;
        // vector<int> dp(n);
        string ans=s;

        reverse(ans.begin(),ans.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==ans[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        int len=dp[n][n];

        return n-len;
        
    }
};