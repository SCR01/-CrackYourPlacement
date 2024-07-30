class Solution {
public:
    int getlength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=getlength(head);
        if(len<k){
            return head;
        }
        int position=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(position<k){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        if(curr!=NULL){
            ListNode* recursionhead=reverseKGroup(curr,k);
            head->next=recursi