class Solution {
public:
    vector<int>g[105];
    int dist[1001][1001];
    int vis[1001][1001];
    int n,m;
    bool f=true,ff=true;;

bool isValid(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(vis[x][y]==1) return false;
    return true;
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs ()
{
    queue<pair<int,int>>q;
   

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j]==1) {
                q.push({i,j});
                dist[i][j]=0;
                f=false;
            } 
            else ff=false;
        }
    }

    while(!q.empty()) {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            if(isValid(cx+dx[i],cy+dy[i])) {
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                vis[nx][ny]=1;
                q.push({nx,ny});
                if(dist[nx][ny]>dist[cx][cy]+1)
                dist[nx][ny]=dist[cx][cy]+1;
            }
        }
    }

}

    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) g[i].push_back(j);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) g[i][j]=grid[i][j];
        }
        memset(dist,1,sizeof(dist));
        bfs();
        int mx=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) mx=max(mx,dist[i][j]);
        }

        if(f || ff) return -1;
        else return mx;

    }
};