class solution{
    public:
    long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long mod=1000000007;
  long long sum1=0;
  long long sum2=0;
  Node* curr1=l1;
  Node* curr2=l2;
  
  while(curr1){
     sum1=(sum1*10)%mod+curr1->data%mod;
     curr1=curr1->next;
  }
  
  while(curr2){
      sum2=(sum2*10)%mod+curr2->data%mod;
      curr2=curr2->next;
  }
  
  long long ans=(sum1*sum2)%mod;
   
   return ans;

}

};

