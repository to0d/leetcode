#include <lt_help/lt.h>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return root != NULL && _isSum(root, sum);
    }

    bool _isSum( TreeNode* node, int sum){      
        sum -= node->val;
        if( node->left == NULL && node->right == NULL )
            return sum == 0;
        return (node->left  != NULL && _isSum(node->left, sum))
            || (node->right != NULL && _isSum(node->right, sum));
    }
};



void test(TreeNode* root, int sum)
{
    cout << "input: sum=" << sum << ", tree=";
    outputTree(root);
    bool r = Solution().hasPathSum(root, sum);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,4,8,11,null,13,4,7,2,null,null,null,1}"), 22);
}

// Result 
//
// 2022-11-23: Runtime 20ms 18.30% Memory 21.4MB 44.72%, https://leetcode.com/problems/path-sum/submissions/848474471/
// 2023-02-22: Runtime 15ms 38.99% Memory 21.4MB 45.59%, https://leetcode.com/problems/path-sum/submissions/902625716/
// 2023-03-08: Runtime 11ms 68.35% Memory 21.3MB 46.14%, https://leetcode.com/problems/path-sum/submissions/911347275/



