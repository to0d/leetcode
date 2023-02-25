#include <lt_help/lt.h>

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int count = 0, lastCount = 0, lastVal = nums[0]-1, size = nums.size();
        for (int i =0; i <= size; ++i)
        {   int num = ( i < size ? nums[i] : (nums[i-1]+1));
            if( num != lastVal )
            {   count += lastCount*(lastCount-1)/2;
                lastVal = num;
                lastCount = 1;
            }
            else
                ++lastCount;
        }
        return count;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().numIdenticalPairs(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,3,1,1,3});
}


// Result 
//
// 2022-12-20: Runtime 4ms 32.90% Memory 7.1MB 93.40%, https://leetcode.com/problems/number-of-good-pairs/submissions/862428784/
// 2023-02-25: Runtime 0ms 100% Memory 7.3MB 16.35%, https://leetcode.com/problems/number-of-good-pairs/submissions/904216652/



