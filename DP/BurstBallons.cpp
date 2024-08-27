class Solution {
public:
    int dfs(vector<int>& nums, vector<vector<int>> &dp, int left, int right){
        if(left > right){
            return 0;
        }
        if(dp[left][right] > 0)
            return dp[left][right];
        int result = 0;
        for(int i=left; i<=right; i++){
            int gain = nums[left-1]*nums[i]*nums[right+1];
            int remaining = dfs(nums, dp, left, i-1) + dfs(nums, dp, i+1, right);
            result = max(result, remaining+gain);
        }
        dp[left][right] = result;
        return result;
    }

    int maxCoins(vector<int>& nums) {
        int total = 0;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>  dp(nums.size(), vector<int>(nums.size(), 0));
        return dfs(nums, dp, 1, nums.size()-2);
    }
};