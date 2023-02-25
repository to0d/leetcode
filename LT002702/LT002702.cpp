#include <lt_help/lt.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, size = nums.size();
        for( int j =0; j < size; ++j )
        {   if( j < size && nums[j] != val )
            {   if( i != j )
                    nums[i] = nums[j];
                ++i; 
            }
        }
        return i;
    }
};


void test(vector<int> nums, int val)
{
    cout << "input: val=" << val << ", nums=";
    outputVector(nums);
    int r = Solution().removeElement(nums, val);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({3,2,2,3}, 3);
}

// Result 
//
// 2023-02-16: Runtime 3ms 60.17% Memory 8.8MB 45.53%, https://leetcode.com/problems/remove-element/submissions/899192400/

