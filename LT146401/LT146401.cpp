#include <lt_help/lt.h>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0;i < 2; ++i)
        {   for(int j = size-1; j > i; --j)
            {   if( nums[j] > nums[j-1])
                {   int v = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = v;
                }
            }
        }
        return (nums[0]-1)*(nums[1]-1);
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
{   test({3,4,5,2});
}


// Result 
//
// 2022-12-15: Runtime 7ms 65.75% Memory 9.9MB 72.17%, https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/860212512/
// 2023-03-11: Runtime 7ms 63.19% Memory 10MB 72.28%, https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/912974641/



