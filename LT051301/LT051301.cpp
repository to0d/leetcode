#include <lt_help/lt.h>

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) { // refer LT010201.cpp
        queue<TreeNode*> nq;
        nq.push(root);
        nq.push(NULL);
        int count = 0, rst = 0;
        while( !nq.empty() )
        {   TreeNode* node = nq.front(); nq.pop();
            if( node == NULL )
            {   if(count == 0)          
                    break;                       // <== main change
                count = 0;
                nq.push(NULL);
            }
            else
            {   if( count++ == 0)                // <== main change
                    rst = node->val;             // <== main change
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
// 2023-03-09: Runtime 14ms 57.59% Memory 21.8MB 44.48%, https://leetcode.com/problems/find-bottom-left-tree-value/submissions/911579393/


