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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head){
            return nullptr;
        }
        ListNode* prev = head;
        int dul_val = head->val;
        ListNode* curr = head->next;
        while (curr){
            if (curr->val != dul_val){
                dul_val = curr->val;
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        if (prev->val == dul_val){
            prev->next = nullptr;
        }
        return head; 
    }
};
