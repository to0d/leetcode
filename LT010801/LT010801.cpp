#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* _sortedArrayToBST(vector<int>& nums, int pos, int len) {
        if(len <= 0) 
            return NULL;
        if(len == 1) 
            new TreeNode(nums[pos]);
        
        int mid = len/2;
        TreeNode* node = new TreeNode(nums[mid+pos]);
        node->left  = _sortedArrayToBST(nums, pos, mid);
        node->right = _sortedArrayToBST(nums, pos+mid+1, len-mid-1);
       
        return node;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    TreeNode* r = Solution().sortedArrayToBST(nums);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}

int main(void)
{
    test({-10,-3,0,5,9});
}


// Result 
//
// 2022-11-30: Runtime 29ms 17.9% Memory 21.9MB 19.30%, https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/852355650/
// 2023-02-18: Runtime 14ms 70.48% Memory 21.9MB 19.6%, https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/900124513/



