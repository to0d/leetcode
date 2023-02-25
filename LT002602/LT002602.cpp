#include <lt_help/lt.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if( size <= 1)
            return size;

        int pos1 = 0;
        for(int pos2 = 1; pos2 < size; ++pos2 )
        {   if( nums[pos1] != nums[pos2] )
            {   if( ++pos1 != pos2)
                    nums[pos1] = nums[pos2];
            }
        }

        return pos1 + 1; 
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().removeDuplicates(nums);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({0,0,1,1,1,2,2,3,3,4});
}

// Result 
//
// 2023-02-16: Runtime 12ms 69.6% Memory 18.3MB 94.33%, https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/899189071/


