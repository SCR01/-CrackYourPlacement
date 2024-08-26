class Solution {
public:
    int maxProfit(int k, vector<int>& p) {

        int n = p.size();

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for(int t=0; t<=k-1; t++) {
                    if(j == 0) {
                        curr[j][t] = max(next[j][t], -p[i] + next[1][t]);
                    }
                    else {
                        curr[j][t] = max(p[i] + next[0][t+1], next[j][t]);
                    }
                }
            }
            next = curr;
        }
        
        return next[0][0];
        
    }
};