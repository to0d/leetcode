#include <lt_help/lt.h>




class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> rst;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push( root );
        nodeQueue.push( NULL );
        double sum = 0;
        int count = 0;

        while( !nodeQueue.empty() )
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if( node == NULL )
            {   if( count > 0 )
                {   rst.push_back( sum/count );
                    count = 0;
                    sum   = 0;
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

        return rst;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<double> r = Solution().averageOfLevels(root);
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
// 2023-01-10: Runtime 11ms 95.22% Memory 22.5MB 75.50%, https://leetcode.com/problems/average-of-levels-in-binary-tree/submissions/875480527/


