#include <lt_help/lt.h>




class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        
        int leftRootUniLen, rightRootUnilen;
        mMaxUniLength = 0;
        
        visitTree(root, leftRootUniLen, rightRootUnilen);
        return mMaxUniLength;
    }
    
    void visitTree(TreeNode* node, int& leftUniLen, int& rightUniLen)
    {
        int LLLen, LRLen, RLLen, RRLen;
        
        if( node == NULL )
        {   leftUniLen  = 0;
            rightUniLen = 0;
            return;
        }
        
        visitTree(node->left, LLLen, LRLen);
        visitTree(node->right, RLLen, RRLen);
    
        if( node->left != NULL && node->val == node->left->val )
            leftUniLen = std::max(LLLen, LRLen) + 1;
        else
            leftUniLen = 0;
        
        if( node->right != NULL && node->val == node->right->val )
            rightUniLen = std::max(RLLen, RRLen) + 1;
        else
            rightUniLen = 0;
        
        mMaxUniLength = std::max((leftUniLen+rightUniLen), mMaxUniLength);
    }
    
private:
    int mMaxUniLength;
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().longestUnivaluePath(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{5,4,5,1,1,null,5}"));
}

// Result 
//
// 2022-11-23: Runtime 145ms 72.74% Memory 72MB 20.51%, https://leetcode.com/problems/longest-univalue-path/submissions/848445787/
