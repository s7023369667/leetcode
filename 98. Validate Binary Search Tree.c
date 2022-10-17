/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool checkBST(TreeNode* root, long lowVal, long highVal){
        if (root == nullptr){
            return true;
        }
        if (!(root->val > lowVal) || !(root->val < highVal)){
            return false;
        }
        return checkBST(root->left, lowVal, root->val) && checkBST(root->right, root->val, highVal);
    }
    
};
