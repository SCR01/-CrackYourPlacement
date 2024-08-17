class DisjointSet {  
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int nodeno = n*i + j;
                            int adjno = n*nr + nc;
                            ds.unionBySize(adjno,nodeno); 
                        }
                    }
                }
            }
        }

        int ans = 1;

        for(int i = 0; i < n*n; i++){
            ans = max(ans,ds.size[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int adjno = n*nr + nc;
                            st.insert(ds.findUPar(adjno));    
                        }
                    }

                    int temps = 1;
                    for(auto it: st){
                        temps += ds.size[it];
                    }
                    ans = max(ans,temps);
                }
            }
        }

        return ans;
    }
};