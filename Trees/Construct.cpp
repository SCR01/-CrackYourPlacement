Node* constTree(int n , int pre[], char preLN[], int &index){
    if(index >= n)return NULL;
    Node* root = new Node(pre[index]);
    index++;
    if(preLN[index -1] == 'N'){
        root->left = constTree(n,  pre, preLN, index);
        root->right = constTree(n, pre, preLN, index);
    }
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n==0) return NULL;
    int index = 0;
    return constTree(n, pre, preLN, index);
}

