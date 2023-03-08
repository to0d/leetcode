#include <lt_help/lt.h>

class Solution {
public:
    int maxLevelSum(TreeNode* root) { // refer LT010201.cpp
        int sum = 0, count = 0, level = 1, maxSum = INT_MIN, maxLevel = -1;
        queue<TreeNode*> nq;
        nq.push(root);
        nq.push(NULL);
        while( !nq.empty() )
        {   TreeNode* node = nq.front(); nq.pop();
            if( node == NULL )
            {   if( count == 0 )
                    break;
                if( sum > maxSum )
                {   maxSum = sum;
                    maxLevel = level;
                }
                count = 0;
                sum   = 0;
                level ++;
                nq.push(NULL);
            }
            else
            {   sum += node->val;
                count++;
                if( node->left != NULL )
                    nq.push(node->left );
                if( node->right != NULL )
                    nq.push(node->right );
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
// 2023-01-13: Runtime 194ms 82.93% Memory 107.3MB 74.12%, https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/877497449/
// 2023-03-09: Runtime 202ms 62.25% Memory 107.4MB 47.55%, https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/911585674/


