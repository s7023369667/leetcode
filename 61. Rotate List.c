/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int value){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node -> val = value;
    node -> next = NULL;
    return node;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head){
        return NULL;
    }
    int len = 0;
    struct ListNode* v = head;
    while (v){
        len += 1;
        v = v->next;
    }
    k %= len;
    for (int i=0;i<k;i++){
        struct ListNode* h = head;
        struct ListNode* new_head = newNode(0);
        for (int j=0;j<len-2;j++){
            h = h->next;
        }
        new_head->val = h->next->val;
        h->next = NULL;
        new_head->next = head;
        head = new_head;
    }
    return head;
}
