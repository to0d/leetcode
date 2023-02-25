#include <lt_help/lt.h>




class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push( root );
        nodeQueue.push( NULL );
        int count = 0, val = 0;

        while( !nodeQueue.empty() )
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if( node == NULL )
            {   if( count > 0 )
                {   count = 0;
                    nodeQueue.push( NULL );
                } 
                else
                   break;
            }
            else
            {
                if(count++ == 0)
                    val = node->val;
                if( node->left != NULL )
                    nodeQueue.push( node->left );
                if( node->right != NULL )
                    nodeQueue.push( node->right );
            }
        }

        return val;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().findBottomLeftValue(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,null,5,6,null,null,7}"));
}

// Result 
//
// 2023-01-08: Runtime 8ms 89.69% Memory 21.8MB 66.57%, https://leetcode.com/problems/find-bottom-left-tree-value/submissions/873815993/


