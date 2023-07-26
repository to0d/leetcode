#include <lt_help/lt.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(int num : nums)
            val ^= num;
        return val;
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
// 2023-07-26: Runtime 8ms 98.76% Memory 16.03MB 85.84%, https://leetcode.cn/problems/single-number/submissions/450334838/

