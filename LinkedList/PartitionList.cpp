class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *list1 = nullptr, *tail1 = nullptr;    // List with val < x
        ListNode *list2 = nullptr, *tail2 = nullptr;    // List with val >= x
        ListNode *p = head;
        while (p) {
            ListNode *node = new ListNode(p->val);
            if (p->val < x) {
                if (!list1) {
                    list1 = node;
                    tail1 = list1;
                } else {
                    tail1->next = node;
                    tail1 = tail1->next;
                }
            } else {
                if (!list2) {
                    list2 = node;
                    tail2 = list2;
                } else {
                    tail2->next = node;
                    tail2 = tail2->next;
                }
            }
            p = p->next;
        }
        if (!list1) return list2;
        
        tail1->next = list2;
        return list1;
    }
};