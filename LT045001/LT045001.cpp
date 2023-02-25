#include <lt_help/lt.h>



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return _deleteNode(root, key);
    }
    
    TreeNode* _deleteNode(TreeNode* node, int key) {
        if( node == NULL )
            return NULL;

        if( node->val == key )
        {   
            if( node->right == NULL)
            {   TreeNode* left = node->left;
                return left;
            }
            
            if( node->right->left == NULL && node->right->right == NULL )
            {   node->val = node->right->val;
                node->right = NULL;
                return node;
            }

            node->right = _deleteMin(node->right, &node->val);
            return node;
        }
        
        if( node->val > key )
            node->left = _deleteNode(node->left, key);
        else
            node->right = _deleteNode(node->right, key);

        return node;
    }
    
    TreeNode* _deleteMin(TreeNode* node, int* val) {
        if( node->left == NULL )
        {   *val = node->val;
            return node->right;
        }
        
        node->left = _deleteMin(node->left, val);
        return node;
    }
};


void test(TreeNode* root, int key)
{
    cout << "input: key=" << key << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().deleteNode(root, key);
    cout << "; output: ";
	outputTree(r);
	cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,3,6,2,4,null,7}"), 3);
}

// Result 
//
// 2023-01-08: Runtime 36ms 73.73% Memory 32.6MB 84.38%, https://leetcode.com/problems/delete-node-in-a-bst/submissions/873743275/


