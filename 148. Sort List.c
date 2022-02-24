/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void printNode(struct ListNode* head){
    while (head != NULL){
        printf("%d ", head->val);
        head = head -> next;
    }
    printf("\n");
}

struct ListNode* bubble_sort(struct ListNode* head){
    //TLE: O(n^2)
    if (head == NULL){
        return head;
    }
    struct ListNode* h = head;
    struct ListNode* i = head;
    struct ListNode* j = head->next;
    while (h->next != NULL){
        while(j != NULL){
            if (i->val > j->val){
                int tmp = j->val;
                j->val = i->val;
                i->val = tmp;
            }
            j  = j-> next;
            i = i->next;
            //printNode(head);
        }
        i = head;
        j = head->next;
        h = h -> next;
    }
    return head;
}


void FrontBackSplite(struct ListNode* source,struct ListNode** frontRef, struct ListNode** backRef){
    struct ListNode* slow = source;
    struct ListNode* fast = source -> next;
    //find middle point ,fast is 2 times faster than slow.
    while (fast != NULL){
        fast = fast -> next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL; 
}


struct ListNode* SortMerge(struct ListNode* a, struct ListNode* b){
    struct ListNode* result = NULL;
    //Base case
    if (a == NULL){
        return b;
    }else if (b == NULL){
        return a;
    }
    //pick into result
    if (a->val <= b->val){
        result = a;
        result->next = SortMerge(a->next, b);
    }else{
        result = b;
        result->next = SortMerge(a, b->next);
    }
    return result;
}

void MergeSort(struct ListNode** headRef){
    struct ListNode* head = *headRef;
    struct ListNode* a;
    struct ListNode* b;
    if ((head == NULL) || (head->next == NULL)){
        return;
    }
    //divide 
    FrontBackSplite(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    //conqure
    *headRef = SortMerge(a, b) ;
}

struct ListNode* sortList(struct ListNode* head){
    MergeSort(&head);  
    return head;
    // return bubble_sort(head);
}


