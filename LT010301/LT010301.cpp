#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( root == NULL )
            return res;
          
        queue<TreeNode*> nodeQueue;
        vector<int> r;
        
        nodeQueue.push(root);
        nodeQueue.push(NULL); // End Mark;
        
        bool leftFirst = true;
        
        while( !nodeQueue.empty() || !r.empty() )
        {
            TreeNode* top = NULL;
            if( !nodeQueue.empty() )
            {   top = nodeQueue.front();
                nodeQueue.pop();               
            }
            
            if( top == NULL ) // find end mark
            {   if( r.empty())
                    break;
                if(!leftFirst)
                    std::reverse(r.begin(), r.end());
                res.push_back(r);
                r.clear();
                leftFirst = !leftFirst;
                nodeQueue.push(NULL); // End Mark;
            }
            else
            {   r.push_back( top->val );
                if( top->left != NULL )
                    nodeQueue.push(top->left);
                if( top->right != NULL )
                    nodeQueue.push(top->right);                
            }
        }
        
        return res;
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


