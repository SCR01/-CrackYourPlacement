class Solution {
    private:
        void dfs(int node , vector<int> &list , vector<int> adj[] , int vis[]){
            vis[node] = 1 ;
            list.push_back(node) ;
            
            for(auto it: adj[node]){
                if(vis[it]==0){
                    dfs(it,list,adj,vis);   
                }
            }
        }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] ={0}; 
        vis[0] = 1 ; 
        int start =0 ; 
        vector<int> list ; 
        dfs(start, list, adj, vis); 
        return list;
    }


};