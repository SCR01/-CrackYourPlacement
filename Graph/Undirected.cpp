class Solution {
  public:
    bool dfs(int u, int parent, vector<int> adj[], vector<bool> &vis, vector<bool> &stk){
        vis[u] = true;
        stk[u] = true;
        
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(v,u, adj, vis, stk)) return true;
            }
            else if(stk[v] && parent != v) return true;
        }
        stk[u] = false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> stk(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                if(dfs(i,-1, adj, vis, stk))return true;
            }
        }
        return false;
    }
};