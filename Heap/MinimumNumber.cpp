class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
   int n= stations.size();
        int fuel=startFuel; int fuelno=0;
        int ans=0;
        priority_queue<int> pq;
        while(fuel<target){
           while(fuelno<n && fuel>= stations[fuelno][0]) 
           { 
               pq.push(stations[fuelno][1]);

            fuelno++;
           }
            
            
            
            
            if(pq.empty()) return -1;
          fuel = fuel+ pq.top();
            pq.pop();
            
            ans++;

        }
          return ans;
    }
};