#include <lt_help/lt.h>



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


class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> rst;
        _postorder(root, rst);
        return rst;
    }
    
    void _postorder(Node* node, vector<int>& rst) {
        if( node == NULL )
            return;
        for(Node* child : node->children)
            _postorder(child, rst);
        rst.push_back(node->val);
    }
};


int main(void)
{
    cout << "output: done!" << endl;
}


// Result 
//
// 2023-01-10: Runtime 22ms 77.94% Memory 11.3MB 35.95%, https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/875468583/



