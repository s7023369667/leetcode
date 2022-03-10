/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (!head){
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nxt = head->next;
    while (nxt){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;
    return curr;
}
