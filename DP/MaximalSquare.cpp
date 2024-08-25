class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        if(matrix.empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    int above=dp[i-1][j];
                    int left=dp[i][j-1];
                    int diag=dp[i-1][j-1];
                    dp[i][j]=min(above,min(left,diag))+1;
                    res=max(res,dp[i][j]);
                }
            }   
        }
        return res*res;
    }
};