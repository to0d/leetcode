#include <lt_help/lt.h>



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while (node != NULL || !s.empty() )
        {
            for(; node != NULL ; node = node->left)
                s.push(node);
            
            node = s.top();
            s.pop();
            
            res.push_back(node->val);         
            node = node->right;
        }
        
        return res;
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

