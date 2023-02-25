#include <lt_help/lt.h>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        int size = nums.size(), left = 0, right = sum - nums[0];
        for( int i = 0; i < size; ++i)
        {   if( left == right )
                return i;
            left += nums[i];
            if( (i+1) < size )
                right -= nums[i+1];
        }

        return -1;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().pivotIndex(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,7,3,6,5,6});
}


// Result 
//
// 2022-12-02: Runtime 66ms 18.55% Memory 31.1MB 92.57%, https://leetcode.com/problems/find-pivot-index/submissions/853429619/
// 2023-02-19: Runtime 15ms 98.93% Memory 31.1MB 62.68%, https://leetcode.com/problems/find-pivot-index/submissions/900663448/



