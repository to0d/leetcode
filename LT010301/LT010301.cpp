#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { // refer LT010201.cpp
        vector<vector<int>> rst;
        
        vector<int> nodes;
        queue<TreeNode*> nq;
        nq.push(root);
        nq.push(NULL);
        int level = 0;
        while( !nq.empty() )
        {   TreeNode* node = nq.front(); nq.pop();
            if( node == NULL )
            {   if(nodes.empty())
                    break;
                if( ++level %2 == 0 )
                    std::reverse(nodes.begin(), nodes.end());   // <== main change
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
    vector<vector<int>> r = Solution().zigzagLevelOrder(root);
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
// 2022-11-22: Runtime 7ms 28.88% Memory 11.9MB 93.75%, https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/848097930/
// 2023-02-22: Runtime 4ms 41.42% Memory 12.2MB 17.87%, https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/902638034/
// 2023-03-09: Runtime 3ms 72.4% Memory 12MB 79.15%, https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/911573128/


