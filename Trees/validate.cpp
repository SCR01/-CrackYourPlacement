class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
        if (!root) return true;

        if (minNode && root->val <= minNode->val) {
            return false;
        }
        if (maxNode && root->val >= maxNode->val) {
            return false;
        }

        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};