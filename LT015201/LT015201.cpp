#include <lt_help/lt.h>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size(), e0 = nums[0], rst = e0;
        vector<int> dp_p(size+1, 0), dp_n(size+1, 0);
        dp_p[0] = e0 > 0 ? e0 : 0;
        dp_n[0] = e0 < 0 ? e0 : 0;
        for(int i = 1; i < size; ++i)
        {   int num = nums[i], p = 0, n = 0;
            if( num > 0 )
            {   p = num;
                if( dp_p[i-1] > 0 )
                    p = max(p, dp_p[i-1]*num );
                if( dp_n[i-1] < 0 )
                    n = min(p, dp_n[i-1]*num );
            }
            else if( num < 0 )
            {   n = num;
                if( dp_p[i-1] > 0 )
                    n = min(p, dp_p[i-1]*num );
                if( dp_n[i-1] < 0 )
                    p = max(p, dp_n[i-1]*num );
            }
            if( p > 0 )
                dp_p[i] = p;
            if( n < 0 )
                dp_n[i] = n;
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





