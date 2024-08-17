class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        //in this alien dictionary question once you are able to crack
        //that how to make a link between the alphabet as per the 
        //customised dictionary then after that you can easily able use 
        //topo sort here
        
        
        //int this we can clearly see that if a word is occuring first then
        //the first letter that differ between those word will have an edge
        //as the word 1st having the differ letter has the high priority
        //than the word 2nd at which we got differ element
        
        //here we made the adjacency matrix with help of map
        //as mp[i] have all its child(neighbour) where i is 
        //the node(parent node)
        map<int,vector<int>>mp;
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j < min(dict[i].size(),dict[i+1].size()); j++){
                if(dict[i][j] != dict[i+1][j]){
                    mp[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        queue<int>q;
        vector<int>in(K,0);
        // we just kept the indgree of each node in in[] vector
        for(int i = 0; i < K; i++){
            for(int j = 0; j < mp[i].size(); j++){
                in[mp[i][j]]++;
            }
        }
        //now we push all the element which has 0 indegree to our queue i.e. q
        for(int i = 0; i < K; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        //we keep vector v such as to find the topo sort and if
        //the size of v is eual to the number of node the this 
        //bunch of number are in correct order
        vector<int>v;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            v.push_back(x);
            for(int i = 0; i < mp[x].size(); i++){
                in[mp[x][i]]--;
                if(in[mp[x][i]] == 0){
                    q.push(mp[x][i]);
                }
            }
        }
        //as per question we just need to put all elementf of topo 
        //sort path in string and we just need to return that only
        //so we just iterate on v and add the element in string ans
        string ans = "";
        for(auto i : v){
            ans+=char(i+'a');
        }
        //finally we return the string ans as required by the question
        return ans;
    }
};