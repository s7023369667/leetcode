/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != '\0'){
        if (fast->next != '\0'){
            //eventhought, fast->next->next is NULL.
            fast = fast->next->next;
        }else{
            break;
        }
        slow = slow->next;
    }
    return slow;
}


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head -> next;
    while (fast != '\0'){
        fast = fast->next;
        if (fast!='\0'){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
