/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void setNext(struct Node* root){
    if (!root->left){
        return;
    }
    root->left->next = root->right;
    if (!root->next){
        //The most right root case.
        root->right->next = NULL;
    }else{
        //The other root case.
        root->right->next = root->next->left;
    }
    setNext(root->left);
    setNext(root->right);
}


struct Node* connect(struct Node* root) {
    if (!root){
        return NULL;
    }
    setNext(root);
    return root;
}
