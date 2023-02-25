#include <lt_help/lt.h>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low >=0 && low <= high )
        {   int m = ( high + low ) / 2;
            int v = nums[m] ;
            if( v > target )
                high = m - 1;
            else if( v < target )
                low = m + 1;
            else
                return  m;
        }

        return high + 1;
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", target=" << target;
    int r = Solution().searchInsert(nums, target);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,3,5,6}, 2);
}

// Result 
//
// 2022-11-24: Runtime 10ms 25.89% Memory 9.7MB 30.43%, https://leetcode.com/problems/search-insert-position/submissions/848897115/
// 2023-02-17: Runtime 0ms 100% Memory 9.7MB 77.55%, https://leetcode.com/problems/search-insert-position/submissions/899506802/

