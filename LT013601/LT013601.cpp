#include <lt_help/lt.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0, size = nums.size();
        for( int i = 0;i < size; ++i)
            n ^= nums[i];
        return n;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";  
    outputVector(nums); 
    int r = Solution().singleNumber(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({2,2,1});
}

// Result 
//
// 2022-11-18: Runtime 38ms 26.7% Memory 17MB 55.80%, https://leetcode.com/problems/single-number/submissions/845882748/
// 2023-02-19: Runtime 23ms 60% Memory 17MB 56.32%, https://leetcode.com/problems/single-number/submissions/900656659/
