 class Solution {
public:
    int find(int k,int n)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        int ans=1000000;
        for(int i=1;i<=n;i++)  // try from 1 to n floor , drop every floor and find minimum
        { 
          int temp=1+max(find(k-1,i-1),find(k,n-i)) ;  //maximum for worst case
          ans=min(ans,temp);                                     //minimum attempts from maximum temp
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i(included) floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor 
        return find(K,N);
         
    }
};