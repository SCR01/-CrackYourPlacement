class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // creating a map / connection between nodes of each level with their
        // positions as per the horizontal no. line

        //  basically mapping between horizontal no. line distances with level
        //  wise nodes
        map<int, map<int, vector<int>>> nodes;
        // in above map -> int = horizontal distances | second map contains
        // int-> levels & vector/list of nodes at each level

        // this consist of a pair of level & pair of nodes a that level
        queue<pair<TreeNode*, pair<int, int>>> q;
        //  avove q contains -> horizontal distances and level

        // to store the vectors of answers as per sorted order
        vector<vector<int>> finally;

        if (root == NULL) {
            return finally;
        }
        //  making initial pair to push the first level node
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            // taking front node from the queue
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            // temp pair's first is the Node at a level
            TreeNode* frontNode = temp.first;

            // temp pair's second consist of 2 things :-
            // first- horizontal distance
            int hori = temp.second.first;
            // second- at what level the nodes are
            int lvl = temp.second.second;

            // pushing the horixontal dist(int) & level nodes(map-> at what
            // level + list of nodes at that level)
            nodes[hori][lvl].push_back(frontNode->val);

            // iterating to the left direction
            if (frontNode->left) {
                q.push(
                    make_pair(frontNode->left, make_pair(hori - 1, lvl + 1)));
            }
            // iterating to the right direction
            if (frontNode->right) {
                q.push(
                    make_pair(frontNode->right, make_pair(hori + 1, lvl + 1)));
            }
        }

        // extracting values from map and pushing the vector of list of nodes
        // into resultant vector in sorted order
        for (auto i : nodes) {
            vector<int> ans;
            for (auto j : i.second) {
                vector<int> values = j.second;
                sort(values.begin(), values.end());
                ans.insert(ans.end(), values.begin(), values.end());
            }
            finally.push_back(ans);
        }
        return finally;
    }
};