class NestedIterator {
public:
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        NestedInteger n;
        unravel(nestedList, q, n);
    }
    
    void unravel(vector<NestedInteger> &nestedList, queue<int>& q, NestedInteger n){
        for (int i=0; i<nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                q.push(nestedList[i].getInteger());
            }
            else{
                unravel(nestedList[i].getList(), q, n);
                
            }
        }
        return ;
    }
    
    int next() {
        int x = q.front();
        q.pop();
        return x;
        
    }
    
    bool hasNext() {
       return !q.empty();        
    }
};