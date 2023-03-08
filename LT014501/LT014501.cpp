#include <lt_help/lt.h>

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> s;
//         TreeNode *node = root, *previsited= NULL;
//         while (node != NULL || !s.empty() )
//         {   for(; node != NULL ; node = node->left)
//                 s.push(node);
//             node = s.top();
//             if( node->right == NULL || previsited == node->right )
//             {   res.push_back(node->val);
//                 s.pop();
//                 previsited = node;
//                 node = NULL;
//             }
//             else 
//                 node = node->right;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        _postorderTraversal(root, res);
        return res;
    }
    
    void _postorderTraversal(TreeNode* node, vector<int>& res) {
        if(node == NULL)
            return;
        if(node->left != NULL)
            _postorderTraversal(node->left, res);
        if(node->right != NULL)
            _postorderTraversal(node->right, res);
        res.push_back(node->val);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().postorderTraversal(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,null,2,3}"));
}

// Result 
//
// 2022-11-23: Runtime 6ms 20.13% Memory 8.4MB 90.65%, https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/848470783/
// 2023-02-22: Runtime 3ms 51.39% Memory 8.3MB 90.76%, https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/902641971/
// 2023-03-08: Runtime 0ms 100% Memory 8.5MB 73.40%, https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/911507128/


