#include <lt_help/lt.h>




// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//        
//         std::stack<TreeNode*> nodeStack;
//         nodeStack.push(root);
//         
//         while( !nodeStack.empty())
//         {
//             TreeNode* pnode = nodeStack.top();
//             nodeStack.pop();
//             
//             if(pnode == NULL)
//                 continue;
//             
//             nodeStack.push(pnode->left);
//             nodeStack.push(pnode->right);
//             
//             TreeNode*temp = pnode->left;
//             pnode->left   = pnode->right;
//             pnode->right  = temp;
//         }
// 
//         return root;
//     }
// };


class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        
        if( root != NULL)
        {
            TreeNode* pnode = invertTree(root->left);
            root->left      = invertTree(root->right);
            root->right     = pnode;         
        }
        
        return root;
    }
};

    
    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    TreeNode* r = Solution().invertTree(root);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,2,7,1,3,6,9}"));
}

// Result 
//
// 2022-11-23: Runtime 0ms 100% Memory 9.7MB 85.60%, https://leetcode.com/problems/invert-binary-tree/submissions/848466491/
