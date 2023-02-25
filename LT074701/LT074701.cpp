#include <lt_help/lt.h>



class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int size = nums.size();
        int max1Idx = 1, max2Idx = 0;
        if( nums[0] > nums[1] )
        {   max1Idx = 0;
            max2Idx = 1;
        }

        for(int i = 2;i < size; ++i)
        {   int v = nums[i];
            if( v <= nums[max2Idx] )
                continue;
            else if( v <= nums[max1Idx] )
                max2Idx = i;
            else
            {   max2Idx = max1Idx;
                max1Idx = i;
            }
        }
        // cout << "m1=" << max1Idx << ", m2=" << max2Idx << endl;
        return nums[max2Idx]*2 <= nums[max1Idx] ? max1Idx : -1;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().dominantIndex(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({3,6,1,0});
}


// Result 
//
// 2022-12-03: Runtime 4ms 54.50% Memory 10.8MB 94.67%, https://leetcode.com/problems/largest-number-at-least-twice-of-others/submissions/853676583/


