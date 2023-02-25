#include <lt_help/lt.h>

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size(), pos = 0;
        while( (pos+1) < size && nums[pos+1] == nums[pos])
            ++pos;

        if( (pos+1) < size )
        {  if(nums[pos+1] > nums[pos])
                while( (pos+1) < size && nums[pos+1] >= nums[pos] )
                    ++pos;
            else
                while( (pos+1) < size && nums[pos+1] <= nums[pos] )
                    ++pos;
        }

        return (pos+1) == size;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bool r = Solution().isMonotonic(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,2,2,3});
}


// Result 
//
// 2022-12-03: Runtime 519ms 5.3% Memory 96.5MB 74.65%, https://leetcode.com/problems/monotonic-array/submissions/853691350/
// 2023-02-18: Runtime 182ms 59.53% Memory 96.4MB 91.59%, https://leetcode.com/problems/monotonic-array/submissions/900122155/



