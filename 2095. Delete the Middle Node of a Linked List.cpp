/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if (slow->next){
            ListNode* nxt = slow->next;
            *slow = *nxt;
            delete nxt;
        }else{
            if (head == slow){
                head = NULL;
            }else{
                head->next = NULL;
            }
        }
        return head;
    }
};
