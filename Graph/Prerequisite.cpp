bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[V];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    int indegree[V] = {0};
	    for(int i = 0; i<V; i++){
	        for(auto it: adj[i])
	        indegree[it]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	    
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(count == V)
	    return 1;
	    
	    return 0;
	}