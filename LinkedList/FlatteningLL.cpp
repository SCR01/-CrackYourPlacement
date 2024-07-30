class Solution {
public:
    void add_at_end(Node *&head,int x)
    {
        static Node *rear=head;
        if(head==NULL)
        {
            head=new Node(x);
            rear=head;
            return;
        }
        rear->next=new Node(x);
        rear=rear->next;
    }
    int reverse(Node *&head)
    {
        Node *curr=head;
        Node *next=NULL;
        Node *prev=NULL;
        int a=0;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            a++;
        }
        head= prev;
        return a;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
       Node *head3=NULL;
       int a=head1->data;
       int b=head2->data;
      while(head1!=NULL && head1->data==0)head1=head1->next;
      while(head2!=NULL && head2->data==0)head2=head2->next;
      Node *_1c=head1;
      Node *_2c=head2;
      Node *h1=head1;
      Node *h2=head2;
      while((h1!=NULL && h2!=NULL)&& (_1c->data==_2c->data))
      {
          _1c=_1c->next;
          _2c=_2c->next;
          h1=h1->next;
          h2=h2->next;
      }
      if(h1==NULL && h2==NULL)
      {
          head3=new Node(0);
          return head3;
      }
       long long int count1=reverse(head1);
       long long int count2=reverse(head2);
       if(count1<count2)
       {
           Node *temp=head1;
           head1=head2;
           head2=temp;
       }
       else if(count1==count2)
       {
          if(_1c->data<_2c->data)
          {
              Node *temp=head1;
              head1=head2;
              head2=temp;
          }
       }
       Node *p=head1;
       Node *q=head2;
       int borrow=0;
       while(q!=NULL)
       {
           int sub=p->data-q->data-borrow;
           borrow=0;
           if(sub<0)
           {
              add_at_end(head3,sub+10);
               borrow=1;
           }
           else
           {
               add_at_end(head3,sub);
           }
           p=p->next;
           q=q->next;
       }
       while(p!=NULL)
       {
           int sum=p->data-borrow;
           borrow=0;
           if(sum<0)
           {
               add_at_end(head3,sum+10);
               borrow= 1;
           }
           else
           {
               add_at_end(head3,sum);
           }
           p=p->next;
       }
       reverse(head3);
       while(head3->data==0)
       {
           head3=head3->next;
           if(head3==NULL)
           {
               head3=new Node(0);
               return head3;
           }
       }
       return head3;
    }
};