#include <lt_help/lt.h>




class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> rst;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push( root );
        nodeQueue.push( NULL );
        int _max = INT_MIN, count = 0;

        while( !nodeQueue.empty() )
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if( node == NULL )
            {   if( count > 0 )
                {   count = 0;                    
                    rst.push_back(_max);
                    _max = INT_MIN;
                    nodeQueue.push( NULL );
                } 
                else
                   break;
            }
            else
            {
                _max = std::max(_max, node->val);
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
    vector<int> r = Solution().largestValues(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,3,2,5,3,null,9}"));
}

// Result 
//
// 2023-01-08: Runtime 11ms 84.3% Memory 22.3MB 43.66%, https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/874080534/


