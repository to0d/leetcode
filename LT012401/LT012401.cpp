#include <lt_help/lt.h>

class Solution {
public:
    int maxPathSum(TreeNode* root) {
		int maxSum = INT_MIN;
		_maxPath(root, maxSum);
		return maxSum;
    }
	
    int _maxPath(TreeNode* node, int& maxSum) {
		int left  = node->left  == NULL ? 0 : _maxPath(node->left, maxSum);
		int right = node->right == NULL ? 0 : _maxPath(node->right, maxSum);
		maxSum = std::max(maxSum, node->val);
		maxSum = std::max(maxSum, node->val + left);
		maxSum = std::max(maxSum, node->val + right);
		maxSum = std::max(maxSum, node->val + left + right); 
		int path  = node->val, maxChild = std::max(left, right);
		if( maxChild > 0 )
		 	path += maxChild;
		return path;
    }
};


    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().maxPathSum(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{-10,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-12-30: Runtime 27ms 71.15% Memory 28.3MB 16.51%, https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/867842033/
// 2023-03-13: Runtime 27ms 66.66% Memory 27.8MB 36.96%, https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/913901613/



