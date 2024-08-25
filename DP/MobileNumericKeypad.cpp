class Solution {
    unordered_set<string>st;
  public:
    vector<vector<string>>ar={
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"},
        {"*", "0", "*"}
    };
    
    long long solve(int i, int j, int n, int track, string temp, vector<vector<vector<long long>>>&dp){
        if(ar[i][j]=="*") return 0;
        if(track==n){
           if(st.find(temp)==st.end()){
               st.insert(temp);
               return 1;
           } 
           return 0;
        }
        if(dp[track][i][j]!=-1) return dp[track][i][j];
        long long left=0, right=0, up=0, down=0;
        long long curr=solve(i, j, n, track+1, temp + ar[i][j], dp);
        if(j-1>=0)
          left=solve(i, j-1, n, track+1, temp + ar[i][j-1], dp);
        if(j+1<3)
          right=solve(i, j+1, n, track+1, temp + ar[i][j+1], dp);
        if(i-1>=0)
          up=solve(i-1, j, n, track+1, temp + ar[i-1][j], dp);
        if(i+1<4)
          down=solve(i+1, j, n, track+1, temp + ar[i+1][j], dp);
        long long ans = curr+left+right+up+down;
        return dp[track][i][j] = ans;
        
    }
    long long getCount(int n) {
        // Your code goes here
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(4, vector<long long>(3, -1)));
        long long count=0;
        for(int i=0; i<=3; i++){
            for(int j=0; j<=2; j++)
              count+=solve(i, j, n, 1, ar[i][j], dp);
        }
        return count;
    }
};