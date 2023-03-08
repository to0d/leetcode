#include <lt_help/lt.h>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) { // refer LT010201.cpp
        vector<int> rst;

        queue<TreeNode*> nq;
        nq.push(root);
        nq.push(NULL);
        int _max = INT_MIN, count = 0;
        while( !nq.empty() )
        {   TreeNode* node = nq.front(); nq.pop();
            if( node == NULL )
            {   if(count == 0)
                    break;
                rst.push_back(_max);
                _max = INT_MIN;
                count = 0;
                nq.push(NULL);
            }
            else
            {   count++;
                _max = std::max(_max, node->val);
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
// 2023-03-09: Runtime 7ms 97.7% Memory 22.2MB 46.45%, https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/911581725/


