#include <lt_help/lt.h>




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        
        TreeNode* last = NULL, *node = NULL;
        for( ; !nodeQueue.empty(); last = node)
        {
            node = nodeQueue.front();
            nodeQueue.pop();
            
            if( node == NULL )
            {
                if( last == NULL )
                    break;
                
                res.push_back(last->val);
                nodeQueue.push(NULL);
            }
            else 
            {
                if( node->left != NULL )
                    nodeQueue.push( node->left );
              
                if( node->right != NULL )
                    nodeQueue.push( node->right );
            }
        }
        return res;
    }
};
    

    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().rightSideView(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,null,5,null,4}"));
}

// Result 
//
// 2022-11-23: Runtime 3ms 78.7% Memory 12.2MB 27.82%, https://leetcode.com/problems/house-robber/submissions/842995826/
