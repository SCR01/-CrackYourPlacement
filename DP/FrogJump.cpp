class Solution {
public:

    bool solve(int idx,int curr_jump,vector<int>& stones,vector<vector<int>>&dp)
    {

        if(idx==stones.size()-1)
        {
            return true;
        }


        if(dp[idx][curr_jump]!=-1)
        {
            if(dp[idx][curr_jump]==1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        for(int i=curr_jump-1; i<=curr_jump+1; i++)
        {
            if(i>0)
            {
                int ele = stones[idx]+i;
                int a = lower_bound(stones.begin()+idx,stones.end(),ele)-stones.begin();

                if(a==stones.size())
                {
                    continue;
                }
                else if(stones[a]!=ele)
                {
                    continue;
                }
                else
                {
                    bool z = solve(a,i,stones,dp);
                    if(z==true)
                    {
                        dp[idx][curr_jump]=1;
                        return true;
                    }
                }
            }
        }

        dp[idx][curr_jump]=0;
        return false;
    }

    bool canCross(vector<int>& stones) {
        

        int idx = 0;
        int curr_jump = 0;
        vector<vector<int>>dp(stones.size()+1,vector<int>(2001,-1));
        bool ans  = solve(idx,curr_jump,stones,dp);

        return ans;
    }
};