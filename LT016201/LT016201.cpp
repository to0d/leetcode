#include <lt_help/lt.h>



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if( size <= 1 ) return 0;
        if( size <= 2 ) return (nums[0] > nums[1] ? 0 : 1);
        if( nums[0] > nums[1] ) return 0;
        if( nums[size-2] < nums[size-1] ) return size-1;
        for(int i = 1; i < size-1; ++i)
        {   if(nums[i-1] < nums[i] && nums[i] > nums[i+1] )
                return i;
        }
        return 0;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findPeakElement(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,2,3,1});
}


// Result 
//
// 2023-01-04: Runtime 8ms 29.40% Memory 8.9MB 31.37%, https://leetcode.com/problems/find-peak-element/submissions/870858454/


