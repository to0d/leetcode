#include <lt_help/lt.h>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low >=0 && low <= high )
        {   int m = ( high + low ) / 2;
            int v = nums[m] ;
            if( v > target )
                high = m - 1;
            else if( v < target )
                low = m + 1;
            else
                return m;
        }

        return -1;        
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);
    int r = Solution().search(nums, target);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({-1,0,3,5,9,12}, 9);
}


// Result 
//
// 2022-12-01: Runtime 130ms 5.6% Memory 27.6MB 68.69%, https://leetcode.com/problems/binary-search/submissions/852620751/
// 2023-02-24: Runtime 39ms 71.79% Memory 27.6MB 69.36%, https://leetcode.com/problems/binary-search/submissions/904188748/

