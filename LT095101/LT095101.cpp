#include <lt_help/lt.h>




class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // cout << "flipEquiv: a="; if (root1 == NULL) cout << "NULL"; else cout << root1->val;
        // cout << ", b="; if (root2 == NULL) cout << "NULL"; else cout << root2->val; cout << endl;

        if( root1 == NULL )
            return root2 == NULL;
        
        if( root2 == NULL )
            return false;
        
        if( root1->val != root2->val )
            return false;
        
        if( flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) )
            return true;
        
        if( flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left) )
            return true;
        
        return false;
    }
};


void test(TreeNode* root1, TreeNode* root2)
{
    cout << "input: r1=";
    outputTree(root1);
    cout << ", r2=";
    outputTree(root2);
    bool r = Solution().flipEquiv(root1, root2);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,5,6,null,null,null,7,8}"), makeTree("{1,3,2,null,6,4,5,null,null,null,null,8,7}"));
}

// Result 
//
// 2023-01-13: Runtime 3ms 81.6% Memory 12.3MB 30.18%, https://leetcode.com/problems/flip-equivalent-binary-trees/submissions/877196237/


