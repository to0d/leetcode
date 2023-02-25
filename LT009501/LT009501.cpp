#include <lt_help/lt.h>



class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> rst;
		_generateTrees(1, n, rst);
		return rst;
    }
	
    void _generateTrees(int n1, int n2, vector<TreeNode*>& rst) {
		rst.clear();
		
		if( n1 > n2 )
		{	rst.push_back(NULL);
			return;
		}

		if( n1==n2 )
		{	rst.push_back(new TreeNode(n1));
			return;
		}

		vector<TreeNode*> left, right;
		for(int i = n1; i <=n2; ++i)
		{	_generateTrees(n1, i-1, left);			
			_generateTrees(i+1, n2, right);
			for( TreeNode* ln : left )
			{	for( TreeNode* rn : right )
				{	TreeNode* node = new TreeNode(i);
					node->left = ln;
					node->right = rn;
					rst.push_back(node);
				}
			}	
		}
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<TreeNode*> r = Solution().generateTrees(n);
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
    test(3);
}

// Result 
//
// 2022-12-28: Runtime 21ms 51.61% Memory 14.9MB 89.10%, https://leetcode.com/problems/unique-binary-search-trees-ii/submissions/867005584/

