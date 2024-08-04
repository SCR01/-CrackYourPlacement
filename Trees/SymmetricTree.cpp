class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true; // An empty tree is symmetric
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()){
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            if(left == NULL  && right == NULL) continue; // Both are NULL, symmetric at this level
            if(left ==NULL  or  right==NULL) return false; // One is NULL and the other is not, not symmetric
            if(left->val != right->val) return false; // Values differ, not symmetric
            // Enqueue children in the order to compare them as mirror images
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true; // tree is symmetric
    }
};