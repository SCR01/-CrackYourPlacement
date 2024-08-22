class Solution {
public:
    

    int solveFindMax(vector<pair<int,int>>&strs,int i,int m,int n)
    {
         if(i>=strs.size())return 0;

         int zeroes = strs[i].first;
         int ones = strs[i].second;
         int include=0,exclude=0;

         if(m-zeroes >=0 && n-ones>=0)
         {
            include = 1 + solveFindMax(strs,i+1,m-zeroes,n-ones);
         }
         exclude = solveFindMax(strs,i+1,m,n);

         return max(include,exclude);
    }

    int memoFindMax(vector<pair<int,int>>&strs,int i, int m,int n, vector<vector<vector<int>>>&dp)
    {
       
        if(i>=strs.size())return 0;

        if(dp[i][m][n]!=-1)
        {  
            // cout<<"Hello"<<endl;
            return dp[i][m][n];        
        }

         int zeroes = strs[i].first;
         int ones = strs[i].second;
         int include=0,exclude=0;

         if(m-zeroes >=0 && n-ones>=0)
         {
            include = 1 + memoFindMax(strs,i+1,m-zeroes,n-ones,dp);
         }
         exclude = memoFindMax(strs,i+1,m,n,dp);
         
         dp[i][m][n] = max(include,exclude);


         return dp[i][m][n] ;

    }

    int tabuFindMax(vector<pair<int,int>>&strs,int m, int n)
    {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        for(int i = strs.size()-1;i>=0;i--)
        {
            for( int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int zeroes = strs[i].first;
                    int ones = strs[i].second;
                    int include=0,exclude=0;

                    if(j-zeroes >=0 && k-ones>=0)
                    {
                        include = 1 + dp[i+1][j-zeroes][k-ones];
                    }
                    exclude = dp[i+1][j][k];
         
                    dp[i][j][k] = max(include,exclude);
                }
            }
        }

        return dp[0][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>>str1; // to store the pairs of {zeros,ones} of every string present in the strs vector
        for(auto s:strs)
        {
            int ones=0,zeros=0;
            for(auto ch:s)
            {
                if(ch=='1')ones++;
                if(ch=='0')zeros++;
            }
            str1.push_back({zeros,ones});
            // cout<<zeros<<" "<<ones<<endl;
        }

        int i=0;

        // int ans = solveFindMax(str1,i,m,n);

        vector<vector<vector<int>>>dp(str1.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        // int ans2 = memoFindMax(str1,i,m,n,dp);
        int ans3 = tabuFindMax(str1,m,n);
        return ans3;


    }
};