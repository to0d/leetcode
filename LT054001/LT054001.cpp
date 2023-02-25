#include <lt_help/lt.h>



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = 0;
        for( int i = 0;i <(int) nums.size(); ++i)
            n ^= nums[i];
        return n;
    }
};

void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().singleNonDuplicate(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,1,2,3,3,4,4,8,8});
}

// Result 
//
// 2023-01-15: Runtime 31ms 51.84% Memory 22.3MB 62.44%, https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/878447588/
