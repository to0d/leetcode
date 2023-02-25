#include <lt_help/lt.h>




class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int sum = 0, count = 0, level = 1, maxSum = INT_MIN, maxLevel = -1;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push( root );
        nodeQueue.push( NULL );

        while( !nodeQueue.empty() )
        {   TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if( node == NULL )
            {   if( count > 0 )
                {   if( sum > maxSum )
                    {   maxSum = sum;
                        maxLevel = level;
                    }
                    sum = 0;
                    count = 0;
                    level++;
                    nodeQueue.push( NULL );
                }
                else
                   break;
            }
            else
            {   sum += node->val;
                count++;
                if( node->left != NULL )
                    nodeQueue.push( node->left );
                if( node->right != NULL )
                    nodeQueue.push( node->right );
            }
        }

        return maxLevel;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().maxLevelSum(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,7,0,7,-8,null,null}"));
}

// Result 
//
// 2023-01-13: Runtime nullms 82.93% Memory 107.3MB 74.12%, https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/877497449/


