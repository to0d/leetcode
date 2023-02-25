#include <lt_help/lt.h>




class Solution {
    enum TreeType
    {   FullComplete, InComplete, PartComplete
    };
    
public:
    bool isCompleteTree(TreeNode* root) {
        int deep = 0;
        return _completeOfTree(root, deep) != InComplete;
    }
    
    TreeType _completeOfTree(TreeNode* node, int& deep)
    {   if( node == NULL )
        {   deep = 0;
            return FullComplete;
        }

        int ld = 0, rd = 0;
        TreeType lt = _completeOfTree( node->left, ld);
        if( lt  == InComplete )
            return InComplete;
        
        TreeType rt = _completeOfTree( node->right, rd);
        if( rt  == InComplete )
            return InComplete;
        
        deep = ld + 1;
        if( ld == rd && lt == FullComplete)
            return rt; 

        if(ld == (rd+1) && lt == FullComplete)
            return PartComplete; 
        
        if(ld == (rd+1) && lt == PartComplete && rt == FullComplete)
            return PartComplete; 

        return InComplete;
    }
};

void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    bool r = Solution().isCompleteTree(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,5,6}"));
}

// Result 
//
// 2023-01-13: Runtime 3ms 88.69% Memory 10.3MB 93.65%, https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/877461429/


