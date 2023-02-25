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
    int maxDepth(Node* root) {
        if( root == NULL )
            return 0;
        int child_size = root->children.size();
        if( child_size == 0 )
            return 1;
        int _max = -1;
        for( Node* child : root->children)
        {   _max = std::max(_max, maxDepth(child));
        }
        return _max + 1;
    }
};


int main(void)
{
    cout << "output: done!" << endl;
}


// Result 
//
// 2023-01-09: Runtime 15ms 82.44% Memory 10.9MB 40.93%, https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/874809111/



