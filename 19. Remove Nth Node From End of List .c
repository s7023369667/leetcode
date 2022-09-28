/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int cnt = n;
    struct ListNode* pScan = head;
    while ((cnt--) > 0){
        pScan = pScan->next; //tricky part
    }
    if (!pScan){
        return head->next;
    }
    struct ListNode* pDel = head; 
    while (pScan->next){
        pScan = pScan->next;
        pDel = pDel->next;
    }
    pDel->next = pDel->next->next;
    return head;
}
