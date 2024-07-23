class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long> ans;
       long long result=1;
       for(int i=0;i<n;i++){
           if(nums[i]!=0){
               result=result*nums[i];
           }
           else{
               result=result*1;
           }
       }

        bool flag=0;
        int cnt=0;
       for(int i=0;i<n;i++){
          if(nums[i]==0){
              cnt++;
               flag=1;
           }
       }
       if(flag==0){
           for(int i=0;i<n;i++){
               ans.push_back(result/nums[i]);
           }
       }
       else if(cnt==1 && flag==1){
           for(int i=0;i<n;i++){
               if(nums[i]!=0)
                ans.push_back(0);
               else
                ans.push_back(result);
           }
       }
       else if(cnt>1){
           for(int i=0;i<n;i++){
               ans.push_back(0);
           }
       }
      return ans;
        //code here        
    }
};