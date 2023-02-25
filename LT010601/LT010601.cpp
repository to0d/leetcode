#include <lt_help/lt.h>



class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        hmap.clear();
        for(int i = 0;i < inorder.size(); ++i)
            hmap[inorder[i]] = i;
        
        return buildTree( inorder, 0, postorder, 0, inorder.size() );
    }
    
    TreeNode* buildTree(vector<int>& inorder, int inStart,
                        vector<int>& postorder, int postStart, 
                        int length) 
    {
        if( length <= 0 ) return NULL;
        
        int val = postorder[ postStart + length - 1];
        int vind = hmap[val];
        
        TreeNode* node = new TreeNode(val);
        node->left = buildTree( inorder, inStart, 
                                postorder, postStart, 
                                vind - inStart);
                                
        node->right = buildTree( inorder, vind + 1, 
                                 postorder, postStart + vind - inStart, 
                                 length - 1 - vind + inStart);
        
        return node;
    }
    
    unordered_map<int,int> hmap;
};


void test(vector<int> inorder, vector<int> postorder)
{
    cout << "input: inorder=";
    outputVector(inorder);
    cout << ", postorder=";
    outputVector(postorder);
    TreeNode* r = Solution().buildTree(inorder, postorder);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test({9,3,15,20,7}, {9,15,7,20,3});
}

// Result 
//
// 2022-11-22: Runtime 11ms 96.56% Memory 26.4MB 62.42%, https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/848103125/

