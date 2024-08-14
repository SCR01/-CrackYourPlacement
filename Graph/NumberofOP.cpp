class Solution {
private:
    vector<int> parent; // To store the parent of each node
    vector<int> rankk;  // To store the rank (depth) of each tree

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function with union by rank
    void unionSet(int x, int y) {
        x = find(x); // Find root of x
        y = find(y); // Find root of y

        if (rankk[x] < rankk[y]) {
            parent[x] = y; // Attach smaller rank tree under larger rank tree
        } else if (rankk[x] > rankk[y]) {
            parent[y] = x;
        } else {
            parent[y] = x; // Attach one tree under another and increase rank
            rankk[x]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = n; // Initially, assume all nodes are separate components
        parent.resize(n);    // Resize parent vector to accommodate n nodes
        rankk.resize(n, 0);  // Initialize rank vector with 0

        // If there are not enough connections to connect all nodes, return -1
        if (connections.size() < n - 1) return -1;

        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Process each connection
        for (auto& vec : connections) {
            // If the nodes are not already connected, connect them
            if (find(vec[0]) != find(vec[1])) {
                unionSet(vec[0], vec[1]);
                components--; // Decrease the number of components
            }
        }

        // Return the number of operations needed to connect all components
        return components - 1;
    }
};
