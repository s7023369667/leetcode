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

class Solution {
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
