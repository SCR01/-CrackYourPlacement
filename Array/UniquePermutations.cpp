class Solution {
  public:
   void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&v,int freq[]){
      if(v.size()==arr.size()){
          ans.push_back(v);
          return;
      }
      for(int i=0;i<arr.size();i++){
          if(!freq[i]){
              v.push_back(arr[i]);
              freq[i]=1;
              solve(arr,ans,v,freq);
              freq[i]=0;
              v.pop_back();
          }
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>>ans;
        vector<int>v;
        int *freq=new int[arr.size()];
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
        solve(arr,ans,v,freq);
        sort(ans.begin(),ans.end());
          auto it 
        = unique(ans.begin(), ans.end()); 
  
    // Use erase method  to remove all the duplicates 
    // from the vector 
    ans.erase(it, ans.end()); 
    
        return ans;
    }
};