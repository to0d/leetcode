#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> r;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push( root );
        nodeQueue.push( NULL );
        
        while( !nodeQueue.empty() )
        {   TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if( node == NULL )
            {   if( !r.empty())
                {   res.push_back(r);
                    r.clear();
                    nodeQueue.push( NULL );
                }   
                else
                    break;
            }
            else
            {   r.push_back( node->val );
                if( node->left != NULL )
                    nodeQueue.push( node->left );
                if( node->right != NULL )
                    nodeQueue.push( node->right );
            }
        }

        reverse(res.begin(), res.end());
        return res;
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



