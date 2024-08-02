class Solution {
public:
   static const int m = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        //compute bounds
        stack<int> l,r;
        int n = A.size(),   bounds[n][2];
        for(int i=0;i<n;++i){
            while(!l.empty() && A[l.top()] > A[i])    l.pop();
            if(l.empty())   bounds[i][0] = -1;
            else bounds[i][0] = l.top();
            l.push(i);
            
            //<= here instead of < provides asymmetry
            //to avoid overcounting duplicates
            while(!r.empty() && A[n-1-i] <= A[r.top()])    r.pop();
            if(r.empty())   bounds[n-1-i][1] = n;
            else bounds[n-1-i][1] = r.top();
            r.push(n-1-i);
        }

        //compute sum
        long res = 0;
        for(int i=0;i<n;++i){
            res = (res + (A[i] * ((i - bounds[i][0]) * (long) (bounds[i][1] - i))%m)%m)%m;
        }
        return res;
    }
};