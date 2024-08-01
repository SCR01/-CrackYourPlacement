int orangesRotting(vector<vector<int>>& grid) {
        // Code here

// queue to store rotten oranges initially
        queue <pair<pair<int,int>,int>>q;

// vector to check if any grid with value one left unreached at the end
        vector<vector<int>>vec(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    
                }
                if(grid[i][j]==1){

initialise grid with one in vec[i][j] =1

                    vec[i][j]=1;
                }
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        int maxt=0;
        // standard bfs traversal
       while(!q.empty()){
            int siz=q.size();
            while(siz--){
                pair<int,int>p=q.front().first;
               int t=q.front().second;
               q.pop();
               int a=p.first;
               int b=p.second;
                maxt=max(maxt,t);

// traverse to gird =1 from rotten grid =2

               if(a-1>=0&&grid[a-1][b]==1){

// insert that grid with time t+1
                   q.push({{a-1,b},t+1});

// put grid value to 2 so that it will not be considered to traverse again
                   grid[a-1][b]=2;

//put zero in vec[a-1][b] to 1 which was originally 1
                   vec[a-1][b]=0;
               }
               if(b-1>=0&&grid[a][b-1]==1){
                   q.push({{a,b-1},t+1});
                   grid[a][b-1]=2;
                   vec[a][b-1]=0;
               }
               if(a+1<grid.size()&&grid[a+1][b]==1){
                   q.push({{a+1,b},t+1});
                    grid[a+1][b]=2;
                   vec[a+1][b]=0;
               }
               if(b+1<grid[0].size()&&grid[a][b+1]==1){
                   vec[a][b+1]=0;
                   grid[a][b+1]=2;
                   q.push({{a,b+1},t+1});
               }
                
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

// if any vector contains 1 that means it was not traversed and answer // has to be -1
                if(vec[i][j]==1){
                    return -1;
                }
            }
        }
        return maxt;
    }

