#include <lt_help/lt.h>



class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> rst;
        _allPossibleFBT(n, rst);
        return rst;
    }
    
    void _allPossibleFBT(int n, vector<TreeNode*>& rst) {
        rst.clear();
        if( n%2 == 0)
            return;
        if( n == 1 )
        {   rst.push_back(new TreeNode(0));
            return;
        }
        vector<TreeNode*> left, right;
        for(int i = 1; i < n; i+= 2)
        {   _allPossibleFBT(i, left);
            _allPossibleFBT(n-1-i, right);
            for( TreeNode* lc : left )
                for( TreeNode* rc : right )
                {   TreeNode* root = new TreeNode(0);
                    root->left = lc;
                    root->right = rc;
                    rst.push_back(root);
                }
        }
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<TreeNode*> r = Solution().allPossibleFBT(n);
    cout << "; output: [";
	int i = 0;
	for( TreeNode* n : r )
    {	if( i != 0)
            std::cout << ", ";
		outputTree(n);
	}
	cout << "];" << endl;
}


int main(void)
{
    test(5);
}

// Result 
//
// 2023-01-30: Runtime 109ms 58.57% Memory 34.5MB 49.82%, https://leetcode.com/problems/all-possible-full-binary-trees/submissions/888136655/

