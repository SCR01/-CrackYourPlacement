class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        while(!st.empty() || root){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            ans.push_back(root->val);

            st.pop();
            root=root->right;
        }
        return ans;
    }
};