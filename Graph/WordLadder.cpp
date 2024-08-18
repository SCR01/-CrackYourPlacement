class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        wl.insert(wl.begin(), bw);
        int n = wl.size();
        int ewIndex = -1;

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            if (wl[i] == ew) ewIndex = i;
            for (int j = i + 1; j < n; j++) {
                int matched = 0;
                for (int k = 0; k < bw.size(); k++) {
                    if (wl[i][k] == wl[j][k]) matched++;
                }
                if (matched == bw.size() - 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        if (ewIndex == -1) return 0; 
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (distance[node] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distance[ewIndex] == INT_MAX ? 0 : distance[ewIndex] + 1;
    }
};