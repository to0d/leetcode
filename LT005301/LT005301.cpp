#include <lt_help/lt.h>

//        + 
//       + +            +           +
//     +     +         +   +      +   +
// ---------------------------------------> index: 0,1,2...n
//           | +    +      |+   +
//  			|  + +        |  +
//           v             v
//          max0         max1        max2   ....
//          
// 
// MaxSub =  Max(Xi) - Min(Xj) ; when i > j

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if( len == 0 )
            return 0;
        if( len == 1)
            return nums[0];

        int i = 0, val, max = INT_MIN;                  //-2147483648  
        for (; i < len && (val = nums.at(i)) < 0; ++i ) // find max value in negate numbers
        {   if( val > max )
                max = val; 
        }

        if( i == len )
            return max;

        for(int min = 0, sum = 0; i < len; ++i )
        {   sum += nums[i];
            if ( sum < min )
                min = sum;
            else
            {   int sub = sum - min;
                if( sub > max)
                    max = sub;
            }
        }

        return max;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums); 
    int r = Solution().maxSubArray(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({-2,1,-3,4,-1,2,1,-5,4});
}

// Result 
//
// 2022-11-16: Runtime 344ms 6% Memory 67.8MB 16.10%, https://leetcode.com/problems/maximum-subarray/submissions/844590182/
// 2023-02-17: Runtime 125ms 49.56% Memory 67.8MB 17.16%, https://leetcode.com/problems/maximum-subarray/submissions/899817811/


