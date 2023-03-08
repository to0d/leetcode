#include <lt_help/lt.h>

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if( root == NULL )
            return false;
        return isSameTree(root, subRoot) 
            || isSubtree(root->left, subRoot) 
            || isSubtree(root->right, subRoot);
    }    

    bool isSameTree(TreeNode* p, TreeNode* q) { // refer LT010001.cpp
        if( p == NULL )
            return q == NULL;
        if( q == NULL || p->val != q->val )
            return false;
        return isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
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
// 2023-03-09: Runtime 10ms 99.85% Memory 28.9MB 61.45%, https://leetcode.com/problems/subtree-of-another-tree/submissions/911564531/


