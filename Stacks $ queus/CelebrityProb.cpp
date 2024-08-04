class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int> in(n,0),out(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    in[j]++;
                    out[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(in[i] == n-1 and out[i] == 0) return i;
        }
        return -1;
    }
};