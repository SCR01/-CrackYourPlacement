class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<set<int>> nodes;
        int a = -1, b = -1;

        for(int i=0; i<edges.size(); i++)
        {
            a = -1, b = -1;

            for(int j=0; j<nodes.size(); j++)
            {
                if(nodes[j].find(edges[i][0])!= nodes[j].end())
                    a = j;
                if(nodes[j].find(edges[i][1])!= nodes[j].end())
                    b = j;
                if(a!=-1 && b!=-1)
                    break;
            }
            if(a==-1 && b==-1)
                nodes.push_back(set<int>(edges[i].begin(), edges[i].end()));
            else if(a==b)
                return edges[i];
            else if(a==-1)
                nodes[b].insert(edges[i][0]);
            else if(b==-1)
                nodes[a].insert(edges[i][1]);
            else
            {
                nodes[a].insert(nodes[b].begin(), nodes[b].end());
                nodes.erase(nodes.begin()+b);
            }
        }
        return {};
    }
};
