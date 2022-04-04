/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

swap the nodes values counting from begin to kth and counting from end to kth
struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* tmp = head;
    int n = 0;
    while (tmp){
        n++;
        tmp = tmp->next;
    }
    tmp = head;
    struct ListNode *v1 = NULL, *v2 = NULL;
    int idx = 1;
    while (tmp){
        if (idx == k){
            v1 = tmp;
        }
        if (idx == n-k+1){
            v2 = tmp;
        }
        tmp = tmp->next;
        idx ++;
    }
    int value = v1->val;
    v1->val = v2->val;
    v2->val = value;
    return head;
}

struct ListNode* swapNodes(struct ListNode* head, int k){
    if (!head || k<1){
        return head;
    }
    struct ListNode* begin = head;
    struct ListNode* end = head;
    struct ListNode* current = head;
    int i = 1;
    while (i<k && current){
        //printf("%d ", current->val);
        current = current->next;
        begin = begin->next;
        i++;
    }
    //printf("%d ", current->val);
    //printf("\n");
    while (current->next){
        //printf("%d ", end->val);
        current = current->next;
        end = end->next;
    }
    //printf("%d ", end->val);
    //printf("\n");
    
    
    int value = begin->val;
    begin->val = end->val;
    end->val = value;
    return head;
}
