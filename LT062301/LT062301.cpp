#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return _addOneRow(root, 1, true, val, depth);
    }
    
    TreeNode* _addOneRow(TreeNode* node, int curDepth, bool fromLeft, int val, int depth) {
        if( curDepth == depth )
        {   TreeNode* newNode = new TreeNode(val);
            if( fromLeft )
                newNode->left = node;
            else
                newNode->right = node;
            return newNode;
        }
        
        if( node->left != NULL )
            node->left = _addOneRow(node->left, curDepth+1, true, val, depth);
        else if ((curDepth+1) == depth)
            node->left = new TreeNode(val);

        if( node->right != NULL )
            node->right = _addOneRow(node->right, curDepth+1, false, val, depth);
        else if ((curDepth+1) == depth)
            node->right = new TreeNode(val);

        return node;
    }
};



void test(TreeNode* root, int val, int depth)
{
    cout << "input: val=" << val << ", depth=" << depth << ", tree=";
    outputTree(root);
    TreeNode* r = Solution().addOneRow(root, val, depth);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{4,2,6,3,1,5}"), 1, 2);
}

// Result 
//
// 2023-01-08: Runtime 29ms 22.93% Memory 24.9MB 86.73%, https://leetcode.com/problems/add-one-row-to-tree/submissions/874100599/
// 2023-02-25: Runtime 23ms 51.31% Memory 24.9MB 68.66%, https://leetcode.com/problems/add-one-row-to-tree/submissions/904435125/



