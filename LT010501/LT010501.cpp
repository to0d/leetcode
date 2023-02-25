#include <lt_help/lt.h>

// **Deduce:**
//
// Add a map to reduce the search time 
class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        hmap.clear();
        for(int i = 0; i< inorder.size(); ++i)
            hmap[inorder[i]] = i;

        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, vector<int>& inorder,  int inStart, int len){
        if( len <= 0) 
            return NULL;

        int rVal = preorder[preStart];
        int rIdx = hmap[rVal];
        int leftLen = rIdx - inStart;
        TreeNode* node = new TreeNode(rVal);
        node->left  = buildTree(preorder, preStart+1, inorder, inStart, leftLen);
        node->right = buildTree(preorder, preStart+1+leftLen, inorder,  rIdx + 1, len - 1 - leftLen);
        return node;
    }
    
    unordered_map<int, int> hmap;
};



void test(vector<int> preorder, vector<int> inorder)
{
    cout << "input: preorder=";
    outputVector(preorder);
    cout << ", inorder=";
    outputVector(inorder);
    TreeNode* r = Solution().buildTree(preorder, inorder);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test({3,9,20,15,7}, {9,3,15,20,7});
}


// Result 
//
// 2022-11-22: Runtime 40ms 36.66% Memory 26.5MB 33.16%, https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/848100921/
// 2023-02-22: Runtime 10ms 97.21% Memory 26.3MB 50.50%, https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/902624492/


