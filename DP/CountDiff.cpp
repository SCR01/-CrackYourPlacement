class Solution {
public:
const int MOD = 1e9 + 7;
long long int dp[1005][1005];
 long long int solve(string& s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if (s[i] == s[j]) {
        int left = i + 1;
        int right = j - 1;

        while (left <= right && s[left] != s[i]) {
            left++;
        }

        while (left <= right && s[right] != s[i]) {
            right--;
        }

        if (left > right) {
            return  dp[i][j]=(2 * solve(s, i + 1, j - 1) + 2) % MOD;
        } else if (left == right) {
            return dp[i][j]=(2 * solve(s, i + 1, j - 1) + 1) % MOD;
        } else {
            return dp[i][j]=(2 * solve(s, i + 1, j - 1) - solve(s, left + 1, right - 1) + MOD) % MOD;
        }
    } else {
        return dp[i][j]=(solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1) + MOD) % MOD;
    }
}

int countPalindromicSubsequences(string s) {
   memset(dp,-1,sizeof(dp));
    int n = s.length();
    return solve(s, 0, n - 1);
}

    // int solve(string s) {
    //     string p=s;
    //     reverse(p.begin(),p.end());
    //     int n=s.size();
    //     int m=p.size();
    // vector<char>ans;
    // int t[n+1][m+1];
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         if(i==0||j==0){
    //             t[i][j]=0;
    //         }
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i-1]==p[j-1]){
    //             t[i][j]=1+t[i-1][j-1];
    //         }
    //         else{
    //             t[i][j]=max(t[i-1][j],t[i][j-1]);
    //         }
    //     }
    // }
    //     int i=n,j=m;
    //     while(i>0 and j>0){
    //         if(s[i-1]==p[j-1]){
    //             ans.push_back(s[i-1]);
    //             i--;j--;
    //         }
    //         else{
    //             if(t[i][j-1]>t[i-1][j]){
    //                 j--;
    //             }
    //             else{
    //                 i--;
    //             }
    //         }
    //     }
    //     return ans.size();
    // }
};