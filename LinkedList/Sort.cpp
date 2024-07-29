class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> sortable;

        ListNode *temp = head;
        while (temp != nullptr) {
            sortable.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(sortable.begin(), sortable.end());

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp -> val = sortable[i++];
            temp = temp -> next;
        }

        return head;
    }
};