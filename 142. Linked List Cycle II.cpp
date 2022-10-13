/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                while (head != slow){
                    /*Assume m is the distance from head to cycle-started node.
                      Assume k is the distance from cycle-started node to the node where fast and slow meeted.
                      Assume l is the length of the cycle.
                      m+k = l*t, where t is the const of int.
                    */
                    head = head -> next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};
