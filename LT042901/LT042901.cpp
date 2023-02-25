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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> rst;
        vector<int> nodes;
        
        queue<Node*> nq;
        nq.push(root);
        nq.push(NULL);
        
        while( !nq.empty() )
        {
            Node* node = nq.front();
            nq.pop();
            
            if( node == NULL )
            {   if(nodes.empty())
                    break;
                rst.push_back(nodes);
                nodes.clear();
                nq.push(NULL);
            }
            else
            {   nodes.push_back(node->val);
                for(Node* child : node->children )
                    nq.push(child);
            }
        }
        
        return rst;
    }
};


int main(void)
{
    cout << "output: done!" << endl;
}


// Result 
//
// 2023-01-11: Runtime 19ms 91.99% Memory 11.5MB 99.69%, https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/876181745/



