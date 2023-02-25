#include <lt_help/lt.h>

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if( root == NULL )
            return false;
        return isEqualtree(root, subRoot) 
            || isSubtree(root->left, subRoot) 
            || isSubtree(root->right, subRoot);
    }
    
    bool isEqualtree(TreeNode* s, TreeNode* t){
        if( s == NULL || t == NULL )
            return s == NULL && t == NULL;
        return s->val == t->val && isEqualtree(s->left, t->left) && isEqualtree(s->right, t->right);
    }
};



void test(TreeNode* root, TreeNode* subRoot)
{
    cout << "input: root=";
    outputTree(root);
    cout << ", subRoot=";
    outputTree(subRoot);
    int r = Solution().isSubtree(root, subRoot);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,4,5,1,2,null,null,null,null,0}"), makeTree("{4,1,2}"));
}

// Result 
//
// 2022-11-23: Runtime 57ms 8.58% Memory 28.9MB 61.80%, https://leetcode.com/problems/subtree-of-another-tree/submissions/848450211/
// 2023-02-24: Runtime 25ms 69.28% Memory 28.8MB 62.23%, https://leetcode.com/problems/subtree-of-another-tree/submissions/904174686/

