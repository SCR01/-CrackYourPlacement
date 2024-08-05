class Solution {

    void dookie(TreeNode* root, bool is_left, int& ans) {
        if(!root) return;

        if(!root->left && !root->right && is_left) {
            ans += root->val;
        }

        dookie(root->left, true, ans);
        dookie(root->right, false, ans);
    }


public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dookie(root, false, ans);

        return ans;
    }
};