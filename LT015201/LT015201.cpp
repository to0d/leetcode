#include <lt_help/lt.h>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size(), e0 = nums[0], rst = e0;
        int dp_p = e0 > 0 ? e0 : 0;
        int dp_n = e0 < 0 ? e0 : 0;
        for(int i = 1; i < size; ++i)
        {   int num = nums[i], p = 0, n = 0;
            if( num > 0 )
            {   p = max(num, dp_p*num);
                n = min(num, dp_n*num );
            }
            else if( num < 0 )
            {   p = max(num, dp_n*num );
                n = min(num, dp_p*num );
            }
            dp_p = p > 0 ? p : 0;
            dp_n = n < 0 ? n : 0;
            rst = max(rst, p);
        }
        return rst;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().maxProduct(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({2,3,-2,4});
}


// Result 
//
// 2023-01-03: Runtime 16ms 15.50% Memory 14.7MB 5.16%, https://leetcode.com/problems/maximum-product-subarray/submissions/870508258/
// 2023-03-12: Runtime 8ms 57.41% Memory 14.1MB 8.37%, https://leetcode.com/problems/maximum-product-subarray/submissions/913876463/
// 2023-05-26: Runtime 6ms 75.90% Memory 13.8MB 36.68%, https://leetcode.com/problems/maximum-product-subarray/submissions/957543868/





