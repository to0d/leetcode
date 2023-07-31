#include <lt_help/lt.h>

class Solution {
public:
#define NUM_MAX  10000
#define NUM_MIN -10000
    int removeDuplicates(vector<int>& nums) {
        int count[NUM_MAX-NUM_MIN+1] = {0};
        int size = nums.size(), pos = 0;
        for(int i = 0; i < size; ++i)
            if( ++count[nums[i]-NUM_MIN] <= 2 )
            {   if( pos != i )
                    nums[pos] = nums[i];
                ++pos;
            }
        return pos;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    auto r = Solution().removeDuplicates(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,1,1,2,2,3});
}

// Result 
//
// 2023-07-31: Runtime 4ms 84.55% Memory 10.43MB 24.05%, https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/submissions/451865869/


