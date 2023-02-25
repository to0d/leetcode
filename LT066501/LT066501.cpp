#include <lt_help/lt.h>

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size(), update = 0;
        for( int i = 1; i < size && update < 2; ++i )
        {   int a = nums[i-1], b = nums[i];
            if( a > b )
            {   update++;
                if( i == 1 || nums[i-2] <= b)   // decrease left number
                    continue;
                else                            // increase right number
                    nums[i] = nums[i-1];
            }
        }

        return update < 2;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bool r = Solution().checkPossibility(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({4,2,3});
}

// Result 
//
// 2022-11-19: Runtime 51ms 20% Memory 7.3MB 20%, https://leetcode.com/problems/non-decreasing-array/submissions/846377232/
// 2023-02-24: Runtime 24ms 85.70% Memory 27.1MB 60.98%, https://leetcode.com/problems/non-decreasing-array/submissions/904184174/


