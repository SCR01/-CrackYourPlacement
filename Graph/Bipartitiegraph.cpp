bool isBipartite(int V, vector<int>adj[]){
        vector<int>color(V,-1);
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=0;
                while(!q.empty())
                {
                    int Node = q.front();
                    q.pop();
                    for(int j=0;j<adj[Node].size();j++)
                    {
                        if(color[adj[Node][j]]==-1)
                        {
                            color[adj[Node][j]]=(color[Node]+1)%2;
                            q.push(adj[Node][j]);
                        }
                        else{
                            if(color[Node]==color[adj[Node][j]])
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }