class Solution {
  public:
  int res=0;
  int solve(string &str1,string &str2,vector<vector<int>>&dp,int i,int j){
      
      if(i>=str1.length() || j>=str2.length())
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      int ans=0;
      if(str1[i]==str2[j])
      ans=1+solve(str1,str2,dp,i+1,j+1);
      solve(str1,str2,dp,i+1,j);
      solve(str1,str2,dp,i,j+1);
      res=max(res,ans);
      return dp[i][j]=ans;
  }
    int longestCommonSubstr(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(str1,str2,dp,0,0);
        return res;
    }
};