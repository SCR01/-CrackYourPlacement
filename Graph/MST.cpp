int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>vis(V, 0);
        vector<int>par(V, -1);
        
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>pq;
        
        pq.push({0, {0, -1}});
        //vis[0]=1;
        
        int ans=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int wt=it.first;
            int node=it.second.first;
            int par=it.second.second;
            
            if(vis[node]==1) continue;
            else{
                vis[node]=1;
                ans+=wt;
            }
            
            for(auto &it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if(vis[adjN]==0){
                    pq.push({adjW, {adjN, node}});
                }
            }
        }
        return ans;
    }