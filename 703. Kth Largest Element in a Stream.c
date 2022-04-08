
int cmpfunc(const int* a, const int* b){
    return *b - *a;
}

typedef struct {
    int kth;
    int val;
    struct KthLargest *next;
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    KthLargest* head = (KthLargest*)malloc(sizeof(KthLargest));
    head -> kth = k;
    head -> next = NULL;
    KthLargest* current = head;
    for (int i=0;i<numsSize;i++){
        KthLargest* newNode = (KthLargest*)malloc(sizeof(KthLargest));
        newNode -> val = nums[i];
        newNode -> next = NULL;
        current -> next = newNode;
        current = current -> next;
    }
    return head;
}

int kthLargestAdd(KthLargest* obj, int val) {
    KthLargest* curr = obj;
    KthLargest* nxt = obj->next;
    while (nxt){
        if (nxt->val > val){
            curr = nxt;
            nxt = nxt -> next;
        }else{
            KthLargest* newNode = malloc(sizeof(KthLargest));
            newNode -> val = val;
            curr->next = newNode;
            newNode -> next = nxt;
            break;
        }
    }
    if (!nxt){
        KthLargest* newNode = malloc(sizeof(KthLargest));
        newNode -> val = val;
        curr->next = newNode;
        newNode -> next = nxt;
    }
    curr = obj;
    for (int i=0;i<obj->kth;i++){
        curr = curr->next;
    }
    return curr->val;
}

void kthLargestFree(KthLargest* obj) {
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
