/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* visit = head;
    int cnt = 0;
    while (visit != NULL){
        visit = visit->next;
        cnt += 1;
    }
    int del = cnt - n;
    if (del==0){
        head = head -> next;
    }else{
        struct ListNode* v = head;
        for (int i=1;i<del;i++){
            v = v-> next;
        }
        v->next = v->next->next;
    }
    return head;
}
