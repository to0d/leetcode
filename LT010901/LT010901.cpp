#include <lt_help/lt.h>

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for(; head != NULL; head = head->next )
            nums.push_back(head->val);
        return _makeBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* _makeBST(vector<int>& nums, int start, int end)
    {   if( start > end )
            return NULL;
        int mid = (start + end)/2;
        TreeNode* parent = new TreeNode(nums[mid]);
        parent->left = _makeBST(nums, start, mid-1);
        parent->right = _makeBST(nums, mid+1, end);
        return parent;
    }
};

void test(ListNode* head)
{
    cout << "input: "; 
    outputList(head);  
    TreeNode* r = Solution().sortedListToBST(head);
    cout << "; output: ";
    outputTree(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeList(5,-10,-3,0,5,9));
}

// Result 
//
// 2023-02-01: Runtime 26ms 80.1% Memory 28.7MB 25.73%, https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/889468071/

