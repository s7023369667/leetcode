/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* newNode(int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = newNode(0);
    struct ListNode* visit = head;
    int prev_carry = 0;    
    while (l1 || l2 || prev_carry){
        int tmp1 = 0, tmp2 = 0;
        if (l1){
            tmp1 = l1->val;
            l1 = l1->next;
        }
        if (l2){
            tmp2 = l2->val;
            l2 = l2->next;
        }
        int remain = (tmp1 + tmp2)%10;
        int carry = (tmp1 + tmp2)/10;
        int res = remain + prev_carry;
        if (res==10){
            carry = 1;
            res = 0;
        }
        struct ListNode* tmp = newNode(res);
        visit->next = tmp;
        visit = visit->next;
        prev_carry = carry;
    }
return head->next;
}

