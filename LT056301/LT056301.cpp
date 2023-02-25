#include <lt_help/lt.h>



class Solution {
    
public:

    int findTilt(TreeNode* root) {
        int sum, tilt;
        tilt = 0;
        searchTilt(root, &sum, &tilt);
        return tilt;
    }
    
    void searchTilt(TreeNode* node, int* sum, int* tilt) {
        if( node == NULL )
        {   *sum = 0;
            return;
        }
        
        int leftSum, rightSum;
        searchTilt(node->left, &leftSum, tilt);
        searchTilt(node->right, &rightSum, tilt);
        *sum = node->val;
        *sum += leftSum;
        *sum += rightSum;
        *tilt += (leftSum > rightSum)?(leftSum-rightSum):(rightSum-leftSum);
    }
};


void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().findTilt(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3}"));
}

// Result 
//
// 2022-11-23: Runtime 23ms 52.1% Memory 24.1MB 5.46%, https://leetcode.com/problems/binary-tree-tilt/submissions/848452331/



