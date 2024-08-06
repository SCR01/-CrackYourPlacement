class Solution {
public:
    
    int levelsOfTree(TreeNode* root){
        if(root==NULL) return 0; 
        return 1 + max(levelsOfTree(root->left),levelsOfTree(root->right));
    }
   
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;  // An empty tree is balanced
    
        int LST = levelsOfTree(root->left);
        int RST = levelsOfTree(root->right);
        
        if(abs(LST-RST) > 1) return false;
        
        // Check if the left subtree is balanced
        bool leftBalanced = isBalanced(root->left);
        // Check if the right subtree is balanced
        bool rightBalanced = isBalanced(root->right);
        // when both is balanced then return true
        return leftBalanced && rightBalanced;  
    }
};