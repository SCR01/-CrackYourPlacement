class Solution
{
	public:
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void dfs3rdstep(int node,vector<int>&vis,vector<int>adjT[])
	{
	    vis[node]=1;
	    for(auto it:adjT[node])
	    {
	        if(!vis[it]){
	            dfs3rdstep(it,vis,adjT);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0),vis1(V,0);
        stack<int>st;
        // 1st step is calculating the finish time and store it in a stack
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        // reverse the edges and store it in adjT
        vector<int>adjT[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        // calculate the number of strongly connected components
        int scc=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                dfs3rdstep(node,vis,adjT);
            }
        }
        return scc;
    }
};