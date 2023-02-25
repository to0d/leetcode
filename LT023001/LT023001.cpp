#include <lt_help/lt.h>




class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx = 1;
        TreeNode* node = _kthSmallest(root, k, &idx);
        return node == NULL ? 0 : node->val;
    }
    
    TreeNode* _kthSmallest(TreeNode* node, int k, int* idx) {
        //cout << "find: nod=" << node->val << ", k=" << k << ", idx=" << *idx << endl;
        if(node->left != NULL )
        {   TreeNode* find = _kthSmallest(node->left, k, idx);
            if( find != NULL )
                return find;
        }

        if( (*idx)++ == k )
            return node;

        if(node->right != NULL )
        {   TreeNode* find = _kthSmallest(node->right, k, idx);
            if( find != NULL )
                return find;
        }
        
        return NULL;
    }
};



void test(TreeNode* root, int k)
{
    cout << "input: k=" << k << ", tree=";
    outputTree(root);
    int r = Solution().kthSmallest(root, k);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,3,6,2,4,null,null,1}"), 3);
}

// Result 
//
// 2023-01-10: Runtime 18ms 74.88% Memory 24.1MB 90.39%, https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/875502020/


