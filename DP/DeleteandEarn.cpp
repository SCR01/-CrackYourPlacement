class Solution {
public:

    int term[10001];
    int a[10001];
    int recursiveDaE(int n){
        if (n < 1) return 0;
        else if (n == 1) return a[1];
        else if (n == 2) return a[2];
        else if(term[n] != 0) return term[n];
        else{
            term[n] = a[n] + max(recursiveDaE(n-2), recursiveDaE(n-3));
            return term[n];
        }
        
    }
    int deleteAndEarn(vector<int>& nums) {
        for(int i = 0; i <nums.size(); i++){
            a[nums[i]] += nums[i];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        if (nums.size() == 1) return nums[0]; // to pass testcases that nums.size() = 1
        return max(recursiveDaE(nums[0]),recursiveDaE(nums[0]-1));
    //there are two recursive trees, one starts from n to (n-2,n-3)..., the second one starts from n - 1 to (n-3,n-4)... so we compare two trees
    }
};