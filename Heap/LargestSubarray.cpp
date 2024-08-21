class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<long long, int> mp;
        long long sum=0;
        int maxi=0;

        // sum = 0 is stored as index -1 to get the array size
        mp[0] = -1; 
        
        for (int i=0; i<n; i++){
            sum += arr[I];
            
            // Not found in map
            if(mp.find(sum) == mp.end()){        
                mp[sum] = i;
            }
            // Found in the map
            else { 
                maxi = max(maxi, i - mp[sum]);
            }
        }
        return maxi;
    }
};