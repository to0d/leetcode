#include <lt_help/lt.h>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size(), max_val = nums[0], min_val = INT_MAX, pos1 =-1, pos2=-1;
        for(int i = 1 ; i < size; ++i)
            if( nums[i] < max_val )
            {   pos2 = i;
                if( pos1 == -1 )
                    pos1 = i;
                min_val = min(min_val, nums[i]);
            }
            else
                max_val = nums[i];
        if( pos1 == -1 )
            return 0;
        while( pos1 > 0 && nums[pos1-1] > min_val )
            --pos1;
        return pos2 - pos1 + 1;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findUnsortedSubarray(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({2,6,4,8,10,9,15});
}

// Result 
//
// 2022-11-19: Runtime 25ms 100% Memory 7MB 55.56%, https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/846381552/
// 2023-02-24: Runtime 32ms 80.48% Memory 26.5MB 75.31%, https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/904178596/
// 2023-03-11: Runtime 30ms 82.15% Memory 26.6MB 75.6%, https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/913111302/


