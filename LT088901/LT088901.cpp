#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        m_preIndexMap.clear();
        m_postRightMap.clear();
        _buildIndexMap(preorder, m_preIndexMap);
        _buildIndexMap(postorder, m_postRightMap);
        return _constructFromPrePost(preorder, 0, postorder, 0, postorder.size());
    }
    
    TreeNode* _constructFromPrePost(vector<int>& preorder, int preIndex, vector<int>& postorder, int postIndex, int size) {
        if( size == 0 )
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        if( size == 1 )
            return root;
        
        int val1 = preorder[preIndex+1], val2 = postorder[postIndex+size-2];
        if( val1 == val2 )
            root->left = _constructFromPrePost(preorder, preIndex+1, postorder, postIndex, size-1);
        else
        {   int preIdx2  = m_preIndexMap[val2];
            int postIdx1 = m_postRightMap[val1];
            int leftSize = preIdx2-preIndex-1;
            root->left   = _constructFromPrePost(preorder, preIndex+1, postorder, postIndex, leftSize);
            root->right  = _constructFromPrePost(preorder, preIdx2, postorder, postIdx1+1, size - 1 - leftSize);
        }

        return root;
    }
    
    void _buildIndexMap(vector<int>& vec, unordered_map<int, int>& idxMap){  
        int idx = 0;
        for(int val : vec)
            idxMap[val] = idx++;
    }

    unordered_map<int, int> m_preIndexMap;
    unordered_map<int, int> m_postRightMap;
};



void test(vector<int> preorder, vector<int> postorder)
{
    cout << "input: pre=";
    outputVector(preorder);
    cout << ", post=";
    outputVector(postorder);
    TreeNode* r = Solution().constructFromPrePost(preorder, postorder);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test({1,2,4,5,3,6,7}, {4,5,2,6,7,3,1});
}

// Result 
//
// 2023-01-13: Runtime 23ms 22.15% Memory 27.5MB 11.75%, https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/877178475/
// 2023-02-25: Runtime 17ms 44.32% Memory 27.4MB 11.4%, https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/904428410/



