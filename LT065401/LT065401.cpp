#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        m_map.clear();
        for( int i = 0; i < len; ++i)
            m_map[nums[i]] = i;

        std::sort(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.end());

        TreeNode* root = new TreeNode(nums[0]);
        for( int i = 1; i < len; ++i)
            _buildTree(root, nums[i], _indexOf(nums[i]));

        return root;
    }
    
    void _buildTree(TreeNode* node, int val, int idx){   
        int rootIdx = _indexOf(node->val);
        if( idx > rootIdx )
        {   if (node->right == NULL )
                node->right = new TreeNode(val);
            else
            _buildTree(node->right, val, idx);
        }
        else
        {   if (node->left == NULL )
                node->left = new TreeNode(val);
            else
                _buildTree(node->left, val, idx);
        }
    }
    
    int _indexOf(int val){
        return m_map.find(val)->second;
    }
    
    unordered_map<int,int> m_map;
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    TreeNode* r = Solution().constructMaximumBinaryTree(nums);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}


int main(void)
{
    test({3,2,1,6,0,5});
}

// Result 
//
// 2023-01-11: Runtime 119ms 37.49% Memory 43.1MB 31.82%, https://leetcode.com/problems/maximum-binary-tree/submissions/876195324/
// 2023-02-25: Runtime 112ms 37.74% Memory 43.1MB 31.1%, https://leetcode.com/problems/maximum-binary-tree/submissions/904434226/


