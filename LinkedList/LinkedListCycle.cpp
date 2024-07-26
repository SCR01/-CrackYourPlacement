class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head ) {
            return false;
        }

        return detectCycle(head, head->next);
    }

private:
    bool detectCycle(ListNode *slow, ListNode *fast) {
        if (!fast || !fast->next) {
            return false;
        }

        if (slow == fast) {
            return true;
        }

        return detectCycle(slow->next, fast->next->next);
    }
};