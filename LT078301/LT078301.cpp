#include <lt_help/lt.h>



class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        
        int minVal = INT_MAX, maxVal = INT_MIN, minDiff = INT_MAX;
        _minDiffInBST(root, &minVal, &maxVal, &minDiff);
        return minDiff;
    }
    
    void _minDiffInBST(TreeNode* node, int* minVal, int* maxVal, int* minDiff) {
        // cout << "diff: node=" << node->val << ", min=" << *minVal << ", max=" << *maxVal << ", diff=" << *minDiff << endl;
        int leftMin, leftMax;
        if( node->left != NULL )
        {   _minDiffInBST(node->left, &leftMin, &leftMax, minDiff);
            *minVal = leftMin;
            
            if(*minDiff > 1 )
                *minDiff = std::min(*minDiff, node->val - leftMax);
            else 
                return;
        }
        else
            *minVal = node->val;

        int rightMin, rightMax;
        if( node->right != NULL )
        {   _minDiffInBST(node->right, &rightMin, &rightMax, minDiff);
            *maxVal = rightMax;
            if(*minDiff > 1 )
                *minDiff = std::min(*minDiff, rightMin - node->val);
        }
        else
            *maxVal = node->val;
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().minDiffInBST(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{4,2,6,1,3}"));
}


// Result 
//
// 2022-12-02: Runtime 0ms 100% Memory 9.7MB 92.53%, https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/853268644/


