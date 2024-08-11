class Solution {
public:
    int minCameraCoverHelper(TreeNode* root, int &cam){
        if(root==NULL) return 1;
        
        int left = minCameraCoverHelper(root->left,cam);
        int right = minCameraCoverHelper(root->right,cam);

        if(!(left && right)){
            cam++;
            return 2;
        }
        return max(left,right) -1;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        int cam = 0;
        if(!minCameraCoverHelper(root,cam)) cam++;
        return cam;
    }
};