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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        vector<vector<int>>res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> tmp;
            int q_size = q.size();
            while (q_size){
                TreeNode* currNode = q.front();
                q.pop();
                tmp.push_back(currNode->val);
                if (currNode->left){
                    q.push(currNode->left);
                }
                if (currNode->right){
                    q.push(currNode->right);
                }
                q_size--;
            }
            res.push_back(tmp);
            
        }
        return res;
        
    }

};
