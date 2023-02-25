#include <lt_help/lt.h>




class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while (node != NULL || !s.empty() )
        {
            for(; node != NULL ; node = node->left)
            {   res.push_back(node->val);
                s.push(node);
            }
            
            node = s.top();
            s.pop();
            node = node->right;
        }
        
        return res;
    }
};
    

    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().preorderTraversal(root);
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
// 2022-11-23: Runtime 3ms 50.25% Memory 8.4MB 80.9%, https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/848471870/


