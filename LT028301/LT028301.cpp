#include <lt_help/lt.h>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(), pos = 0;
        for(int i = 0; i < size; ++i)
        {   int num = nums[i];
            if( num != 0 )
            {   if( i != pos )
                    nums[pos] = num;
                ++pos;
            }
        }
        for(; pos < size; ++pos)
            nums[pos] = 0;
    }
};


void test(vector<int> nums)
{
    cout<< "input: "; 
    outputVector(nums);
    Solution().moveZeroes(nums);
    cout<< "; output: ";  
    outputVector(nums);
    cout << ";" << endl;
}

int main(void)
{
    test({0,1,0,3,12});
}

// Result 
//
// 2022-11-19: Runtime 109ms 36.85% Memory 15MB 80.11%, https://leetcode.com/problems/move-zeroes/submissions/846315428/
// 2023-02-22: Runtime 98ms 37.89% Memory 15.3MB 38.81%, https://leetcode.com/problems/move-zeroes/submissions/902732880/
// 2023-02-27: Runtime 23ms 77.66% Memory 19.2MB 65.28%, https://leetcode.com/problems/move-zeroes/submissions/905737593/
// 2023-03-12: Runtime 19ms 92.3% Memory 19.3MB 17.13%, https://leetcode.com/problems/move-zeroes/submissions/913663162/






