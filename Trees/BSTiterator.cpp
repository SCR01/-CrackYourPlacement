class BSTIterator {
public:
//logic is this:Brute force was get the inorder and iterate on it but it has Space Complexity 
//optimal approach =dont store all the nodes is the way to save the Space  complexity...just store elements up to the heigh of the tree
//algo is put elements upto the height of the tree if opne popped then go to right and do the samee thing put the left elements bcz inorder means left node right...first put left and when asked for node put the right subtree left elements
//using stack bcz its lifo and therefore the last left element will be popped first which is what we want for inorder

    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        build(root);
    }
    
    int next() {
        auto x=s.top();
        s.pop();
        build(x->right);
        return x->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void build(TreeNode* node){
        //put elements of the left
        while(node){
            s.push(node);
            node=node->left;
        }
    }
};
