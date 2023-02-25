#include <lt_help/lt.h>



class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        for(int i = 1;i < size; ++i)
            nums[i] += nums[i-1];    
        return nums;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().runningSum(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({1,2,3,4});
}


// Result 
//
// 2022-12-13: Runtime 4ms 61.72% Memory 8.5MB 44.86%, https://leetcode.com/problems/running-sum-of-1d-array/submissions/859212859/



