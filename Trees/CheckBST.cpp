class Solution{
  public:
    bool helper(Node* root,set<int>st)
    {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)
        {
            if(st.find(root->data-1)!=st.end() && st.find(root->data+1)!=st.end()) 
                return true;
        }
        st.insert(root->data);
      return helper(root->left,st) || helper(root->right,st);
    
    }
    bool isDeadEnd(Node *root)
    {
        set<int>st;
        st.insert(0);
        return helper(root,st);
        
    }
};

