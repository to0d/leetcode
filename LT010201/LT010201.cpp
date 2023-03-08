#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        
        vector<int> nodes;
        queue<TreeNode*> nq;
        nq.push(root);
        nq.push(NULL);
        while( !nq.empty() )
        {   TreeNode* node = nq.front(); nq.pop();
            if( node == NULL )
            {   if(nodes.empty())
                    break;
                rst.push_back(nodes);
                nodes.clear();
                nq.push(NULL);
            }
            else
            {   nodes.push_back(node->val);
                if( node->left != NULL )
                    nq.push(node->left );
                if( node->right != NULL )
                    nq.push(node->right );
            }
        }
        return rst;
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<vector<int>> r = Solution().levelOrder(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-11-23: Runtime 3ms 83.91% Memory 12.5MB 86.22%, https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/848479253/
// 2023-03-09: Runtime 0ms 100% Memory 12.5MB 66.53%, https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/911570311/


