class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* node=root;

        int i=1;
        long long int x=LLONG_MAX;

        while(s.size()>0 or node){
            if(node){
                s.push(node);
                node=node->left;
            }

            else{
                TreeNode* temp=s.top();
                s.pop();
                if(i==k) return temp->val;
                if(x!=LLONG_MAX){
                    x=temp->val;
                }
                i++;
                node=temp->right;
            }
            
        }
        return -1;
    }
};