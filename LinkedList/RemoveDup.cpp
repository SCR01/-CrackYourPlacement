class Solution {
public:
    int arr[202];
    ListNode* calc(ListNode* curr,ListNode* pre)
    {
        if(curr==nullptr)return nullptr;    //base case
        if(arr[curr->val +100]>1)           //deletion check
        {
            if(pre==nullptr)                //head node deletion
            {
                ListNode* tmp=calc(curr->next,nullptr);
                delete curr;
                return tmp;
            }
            pre->next=curr->next;           //middle node deletion
            delete curr;
            return calc(pre->next,pre);
        }
        calc(curr->next,curr);              //skipping deletion
        return curr;
    }
    //----------------------------------------------------------------------
    ListNode* deleteDuplicates(ListNode* head) {
        memset(arr,0,sizeof(arr));
        for(ListNode* tmp=head; tmp!=nullptr;tmp=tmp->next)
        {
            arr[tmp->val+100]++;            //+100 used to fit negative numbers in array
        }
        return calc(head,nullptr);
    }
};