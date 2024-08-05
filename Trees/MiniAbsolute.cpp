class Solution {
public:
   TreeNode* prev = nullptr;
    int minDiff = INT_MAX;
    void inorder(TreeNode* node) {
        if (node==NULL) return;
        // Traverse the left subtree
        inorder(node->left);
        // Process the current node
        if(prev != NULL){
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;
        // Traverse the right subtree
        inorder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
           inorder(root);
        return minDiff;
    }
};