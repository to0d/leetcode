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
    vector<int> preorder(Node* root) {
        vector<int> rst;
        _preorder(root, rst);
        return rst;
    }
    
    void _preorder(Node* node, vector<int>& rst) {
        if( node == NULL )
            return;
        rst.push_back(node->val);
        for(Node* child : node->children)
            _preorder(child, rst);
    }
};

int main(void)
{
    cout << "output: done!" << endl;
}


// Result 
//
// 2023-01-10: Runtime 21ms 80.91% Memory 11.1MB 80.42%, https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/875464269/



