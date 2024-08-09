class Solution{
   private:
        Node* lca(Node*root, int a, int b){
            // base case
            if(!root){
                return nullptr;
            }
            if(root->data == a || root->data == b){
                return root;
            }
            
            Node*l = lca(root->left,a,b);
            Node*r = lca(root->right, a,b);
            
            if(l && r) return root;
            if(l) return l;
            else return r;
        }
        
        int len(Node*parent, int val, int cnt){
            // base case
            if(!parent){
                return -1;
            }
            
            if(parent->data == val){
                return cnt;
                
            }
            
            int left = len(parent->left, val, cnt+1);
            if(left !=-1){
                return left;
            }
            
            return len(parent->right,val,cnt+1);
        }
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        // the simple way to solve this 
        // is by finding the lca and then simply traverse from lca to required node
        Node*parent = lca(root,a,b);
        
        int d1 = len(parent, a, 0);
        int d2 = len(parent, b, 0);
        
        return d1 + d2;
    }
};