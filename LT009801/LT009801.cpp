#include <lt_help/lt.h>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return root == NULL || isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode* node, int min, int max){
        if( node->val > max || node->val < min ) 
            return false;
        if( node->left != NULL  && ( node->val == INT_MIN || !isValidBST(node->left, min, node->val-1 )))
            return false;
        if( node->right != NULL && ( node->val == INT_MAX || !isValidBST(node->right,node->val+1, max )))
            return false;
        return true;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);   
    bool r = Solution().isValidBST(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,1,4,null,null,3,6}"));
}


// Result 
//
// 2022-11-22: Runtime 25ms 13.9% Memory 21.5MB 99.83%, https://leetcode.com/problems/validate-binary-search-tree/submissions/848095639/
// 2023-02-22: Runtime 11ms 81.62% Memory 21.8MB 55.14%, https://leetcode.com/problems/validate-binary-search-tree/submissions/902636905/
// 2023-03-13: Runtime 11ms 80.56% Memory 21.7MB 55.59%, https://leetcode.com/problems/validate-binary-search-tree/submissions/913908767/


