#include <lt_help/lt.h>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size(), pos1 = 0, pos2 = 0, sum = 0, minLen = 0;
        while(pos2 < size || ( pos1 < size && sum >= target) )
        {   if( sum >= target )
            {   int len = pos2 - pos1;
                if( minLen == 0 || len < minLen )
                    minLen = len;
                sum -= nums[pos1++];
            }
            else if( pos2 < size )
                sum += nums[pos2++];
        }
        
        return minLen;
    }
};



void test(int target, vector<int> nums)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums); 
    int r = Solution().minSubArrayLen(target, nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(7, {2,3,1,2,4,3});
}

// Result 
//
// 2022-11-16: Runtime 82ms 5.59% Memory 10.5MB 98.76%, https://leetcode.com/problems/minimum-size-subarray-sum/submissions/844595040/
// 2023-02-22: Runtime 38ms 79.24% Memory 28.2MB 92.34%, https://leetcode.com/problems/minimum-size-subarray-sum/submissions/902632090/

