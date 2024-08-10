class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    deque<TreeNode*> dq;
    int level=0;
    dq.push_back(root);
    while(!dq.empty()){
        int l=dq.size();
        vector<int> temp;
        for(int i=0;i<l;i++){
            if(level%2==0){
                TreeNode* node= dq.back();
                dq.pop_back();
                temp.push_back(node->val);
                if(node->left) dq.push_front(node->left);
                if(node->right) dq.push_front(node->right);

            }
            else{
                TreeNode* node= dq.front();
                dq.pop_front();
                temp.push_back(node->val);
                if(node->right) dq.push_back(node->right);
                if(node->left) dq.push_back(node->left);

            }
        }
        level++;
        res.push_back(temp);
    }

    

    return res;
    }
};