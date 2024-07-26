class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int i=0;
        ListNode *ptr=head;
        while(ptr!=nullptr)
        {
            i+=ptr->val;
            ptr=ptr->next;
            if(ptr!=nullptr)
                 i=i*2;
        }
        return i;
    }
};