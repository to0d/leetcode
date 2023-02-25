#include <lt_help/lt.h>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int md = INT_MAX;
        findMinDiff(root, &md, -1, -1);
        return md;
    }
    
    void findMinDiff(TreeNode* node, int* md, int down, int up) {
        if( *md == 1 || node == NULL ) return;
        if( up != -1 )              *md = min(*md, abs(up - node->val));
        if( down != -1 )            *md = min(*md, abs(down - node->val));
        if( node->left != NULL )    findMinDiff(node->left, md, down, node->val);
        if( node->right != NULL )   findMinDiff(node->right, md, node->val, up);
    }

    int abs(int v){
        return v > 0 ? v : -v; 
    }
    
    int min(int a, int b) {
        return a < b ? a : b; 
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().getMinimumDifference(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,2,6,1,3}"));
}

// Result 
//
// 2022-11-23: Runtime 46ms 9.29% Memory 25.1MB 97.5%, https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/848455519/
// 2023-02-24: Runtime 11ms 96.67% Memory 25.3MB 59.5%, https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/904150665/


