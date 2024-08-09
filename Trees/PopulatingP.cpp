

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node *t=q.front();
                q.pop();
                if(t->left!=NULL)q.push(t->left);
                if(t->right!=NULL)q.push(t->right);
                Node *temp=q.front();
                t->next=temp;
                if(i==n-1)t->next=NULL;
            }
        }
        return root;
    }
};