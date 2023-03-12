#include <lt_help/lt.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), rst = 0;
        vector<int> dp(size+1, 0);
        dp[0] = 0;
        for(int i = 0; i < size; ++i)
        {   int num = nums[i], _max = -1;
            for(int j = i-1; j >= 0; --j)
                if( nums[j] < num )
                    _max = max(_max, dp[j+1] );
            dp[i+1] = (_max == -1) ? 1 : _max + 1;
            rst = max( rst, dp[i+1]);
        }
        return rst;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().lengthOfLIS(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({10,9,2,5,3,7,101,18});
}


// Result 
//
// 2023-03-12: Runtime 184ms 73.39% Memory 10.5MB 57.62%, https://leetcode.com/problems/longest-increasing-subsequence/submissions/913658828/


