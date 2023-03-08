#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) { // refer LT010201.cpp
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
        reverse(rst.begin(), rst.end());
        return rst;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<vector<int>> r = Solution().levelOrderBottom(root);
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
// 2022-11-23: Runtime 11ms 15.55% Memory 12.5MB 87.22%, https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/848480397/
// 2023-02-18: Runtime 7ms 43.36% Memory 12.6MB 67.68%, https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/900125915/
// 2023-03-09: Runtime 0ms 100% Memory 12.6MB 37.30%, https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/911575640/



