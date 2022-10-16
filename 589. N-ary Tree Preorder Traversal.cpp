/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution1 {
public:
    void print_stack(stack<Node*> st){
        while (!st.empty()){
            cout << st.top()->val << " ";
            st.pop();
        }
        cout << endl;
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*>st;
        st.push(root);
        while (!st.empty()){
            stack<Node*> stClone = st;
            print_stack(stClone);
            Node* currNode = st.top();
            st.pop();
            res.push_back(currNode->val);
            for (int i=currNode->children.size()-1;i>=0;i--){
                st.push(currNode->children[i]);
            }
        }  
        return res;
    }
};

class Solution2 {
public:
    void traversal(Node* root, vector<int>& res){
        res.push_back(root->val);
        for (Node* child : root->children){
            traversal(child, res);
        }
        
    }
    vector<int> preorder(Node* root) {
        if (root == nullptr){
            return {};
        }
        vector<int> res;
        traversal(root, res);
        return res;

    }
};
