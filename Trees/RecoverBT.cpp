class Solution {

    TreeNode *Prev=nullptr, *First=nullptr , *Sec=nullptr;
      void Inorder(TreeNode* a)
    {
        if(!a) return ;
        Inorder(a->left);

        if(Prev && a->val<Prev->val){
            if(!First) First=Prev;
            Sec=a; 
        } 
      
        Prev=a;
        Inorder(a->right);
    }

public:
    void recoverTree(TreeNode* a) {
        Inorder(a);
        swap(First->val,Sec->val);
    }

};