#include <lt_help/lt.h>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL )
            return q == NULL;

        if( q == NULL || p->val != q->val )
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  
    }
};



void test(TreeNode* p, TreeNode* q)
{
    cout << "input: p=";
    outputTree(p);
    cout << ", q=";
    outputTree(q);
    bool r = Solution().isSameTree(p, q);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3}"), makeTree("{1,2,3}"));
}

// Result 
//
// 2022-11-23: Runtime 8ms 15.87% Memory 9.9MB 80.54%, https://leetcode.com/problems/same-tree/submissions/848365264/
// 2023-02-18: Runtime 0ms 100% Memory 10.1MB 51.33%, https://leetcode.com/problems/same-tree/submissions/900123623/

