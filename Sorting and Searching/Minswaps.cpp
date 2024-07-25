int minSwaps(vector<int>&nums)
    {
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;
        for(int i=0;i<ans.size();i++) {
            mp[ans[i]]=i;
        }
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(mp[nums[i]]!=i) {
                swap(nums[i],nums[mp[nums[i]]]);
                count++;
                i--;
            }
        }
        return count;
    }