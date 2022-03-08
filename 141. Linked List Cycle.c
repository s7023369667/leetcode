/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    while (head){
        if (head->val == -100001){
            return true;
        }
        head->val = -100001;
        head=head->next;
    }
    return false;
}

bool hasCycle(struct ListNode *head){
    if (!head){
        return false;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast){
        fast = fast->next;
        if (fast){
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == fast){
            return true;
        }
    }
    return false;
}
