class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> varray(V,0);
        queue<int> q;
        vector<int>ans;
        varray[0]=1;
        q.push(0);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(int i=0;i<adj[front].size();i++){
                int it = adj[front][i];
                if(varray[it]==0){
                q.push(it);
                varray[it]=1;
                }
            }
            //OR
            
            
            // for(auto it :adj[front]){
            //     if(!varray[it]){
            //         varray[it]=1;
            //         q.push(it);
            //     }
            // }
        }
        return ans;
        
        
    }
};