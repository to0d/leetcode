#include <lt_help/lt.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c[32] = {0}, size = nums.size();
        for( int i = 0;i < size; ++i )
        {   int v = nums[i];
            for( int j = 0; j < 32 && v != 0; ++j)
            {   if( (v & 1) == 1)
                    c[j]++;   
                v = v >> 1;
            }
        }

        int r = 0;
        for( int j = 0; j < 32 ; ++j )
        {   if( (c[j]%3) != 0 )
                r |= 1 << j;
        }

        return r;
    }
};



void test(vector<int> nums)
{
    cout << "input: nums=";  
    outputVector(nums); 
    int r = Solution().singleNumber(nums);
    cout << "; output: ";
    cout << r  << ";" << endl;
}

int main(void)
{
    test({2,2,3,2});
}

// Result 
//
// 2022-11-18: Runtime 14ms 32.49% Memory 9.6MB 66.79%, https://leetcode.com/problems/single-number-ii/submissions/845885248/
// 2023-02-19: Runtime 9ms 68.1% Memory 9.6MB 67.42%, https://leetcode.com/problems/single-number-ii/submissions/900657945/


