#include <lt_help/lt.h>

//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        stack<TreeNode*> s;
//        TreeNode* node = root;
//        while (node != NULL || !s.empty() )
//        {   for(; node != NULL ; node = node->left)
//                s.push(node);
//            node = s.top();
//            s.pop();
//            res.push_back(node->val);         
//            node = node->right;
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        _inorderTraversal(root, res);
        return res;
    }
    
    void _inorderTraversal(TreeNode* node, vector<int>& res) {
        if(node == NULL)
            return;
        if(node->left != NULL)
            _inorderTraversal(node->left, res);
        res.push_back(node->val);
        if(node->right != NULL)
            _inorderTraversal(node->right, res);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);   
    vector<int> r = Solution().inorderTraversal(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,#,2,3}"));
}

// Result 
//
// 2022-11-22: Runtime 0ms 100% Memory 8.4MB 45.87%, https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/848089493/
// 2023-03-08: Runtime 0ms 100% Memory 8.5MB 17.45%, https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/911517317/

