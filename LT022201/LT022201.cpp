#include <lt_help/lt.h>

class Solution {
public:
    int countNodes(TreeNode* root) {
        return _countNodes(root, _getLeftDeep(root), _getRightDeep(root));
    }
    
    int _countNodes(TreeNode* root, int left_deep, int right_deep) {
        if( left_deep == right_deep)
            return pow(2, left_deep) - 1;
        if(root->left == NULL)
            return 1;
        if(root->right == NULL)
            return 2;
        
        int left_count, right_count, left_right_deep = _getRightDeep(root->left);
        if(left_deep == (left_right_deep+1))       // left is completed
        {   left_count = pow(2, left_right_deep) - 1;
            int right_left_deep = _getLeftDeep(root->right);
            if( right_deep == (right_left_deep+1)) // right is completed
                right_count = pow(2, right_left_deep) - 1;
            else
                right_count = _countNodes(root->right, right_left_deep, right_deep-1);
        }
        else    // right is completed
        {   right_count = pow(2, (right_deep-1)) - 1;
            left_count = _countNodes(root->left, left_deep-1, left_right_deep);
        }

        return left_count+right_count+1;
    }
    
    int _getLeftDeep(TreeNode* node) {
        int deep = 0;
        for(; node != NULL; node=node->left)
            ++deep;
        return deep;
    }
    
    int _getRightDeep(TreeNode* node) {
        int deep = 0;
        for(; node != NULL; node=node->right)
            ++deep;
        return deep;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().countNodes(root);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(makeTree("{1,2,3,4,5,6}"));
}


// Result 
//
// 2022-12-05: Runtime 58ms 12.73% Memory 30.8MB 67.19%, https://leetcode.com/problems/count-complete-tree-nodes/submissions/855101919/
// 2023-02-17: Runtime 30ms 90.70% Memory 30.9MB 22.68%, https://leetcode.com/problems/count-complete-tree-nodes/submissions/899798123/



