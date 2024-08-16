class Solution
{
    public:
    void dfs(int node,int V, vector<int> adj[],int visited[],stack<int>& st)
    {
        visited[node]=1;
        
        //visited marked hone ke baad neighbour me jaa
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,V,adj,visited,st);
            }
        }
        
        //node is visisted and explore thus push into the stack
        st.push(node);
    }
public:
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    
    //visited//
    int visited[V]={0};
    //stack//
    stack<int>st;
    
    //har node me traversal
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            //dfs call kar de as visited nhi hai
            dfs(i,V,adj,visited,st);
        }
    }
    
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
 
};
 