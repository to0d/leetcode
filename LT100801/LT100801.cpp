#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return _bstFromPreorder(preorder, 0, preorder.size());
    }
    
    TreeNode* _bstFromPreorder(vector<int>& preorder, int idx, int size) {
        if( size == 0 )
            return NULL;

        int idx2 = -1, val = preorder[idx];        
        for(int i = 1; idx2 == -1 && i < size; ++i )
            if( preorder[idx+i] > val )
                idx2 = i + idx;

        TreeNode* node = new TreeNode(val);
        if( idx2 == -1 )
            node->left = _bstFromPreorder(preorder, idx+1, size-1);
        else
        {   int ls = idx2 - idx - 1;
            int rs = size - ls - 1;
            node->left  = _bstFromPreorder(preorder, idx+1, ls);
            node->right = _bstFromPreorder(preorder, idx2 , rs);
        }

        return node;
    }
};



void test(vector<int> preorder)
{
    cout << "input: ";
    outputVector(preorder);
    TreeNode* r = Solution().bstFromPreorder(preorder);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test({8,5,1,7,10,12});
}

// Result 
//
// 2023-01-13: Runtime 8ms 42.94% Memory 14.2MB 13.59%, https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/877478998/
// 2023-02-25: Runtime 3ms 88.62% Memory 14.3MB 12.62%, https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/904427552/



