#include <lt_help/lt.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0, size = nums.size();
        for(int pos = 0; pos < size; ++pos)
            if( nums[pos] != val && len++ < pos )
                nums[len-1] = nums[pos];
        return len;
    }
};


void test(vector<int> nums, int val)
{
    cout << "input: val=" << val << ", nums=";
    outputVector(nums);
    int r = Solution().removeElement(nums, val);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({3,2,2,3}, 3);
}

// Result 
//
// 2023-02-16: Runtime 3ms 60.17% Memory 8.8MB 45.53%, https://leetcode.com/problems/remove-element/submissions/899192400/
// 2023-07-24: Runtime 0ms 100% Memory 8.30MB 70.58%, https://leetcode.cn/problems/remove-element/submissions/449704649/

