#include <lt_help/lt.h>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size(), begin = -1, end = -1, l = 0, h = size-1;
        while( l <= h && begin == -1)
        {   int m = (l + h)/2;
            int v = nums[m];
            if( v == target )
                begin = m;
            else if (v < target)
                l = m + 1;
            else 
                h = m - 1;
        }
        if( begin != -1 )
        {   while( begin > 0 &&nums[begin-1] == target)
                --begin;
            end = begin;
            while( (end+1) < size &&nums[end+1] == target)
                ++end;
        }
        return {begin, end};
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", target=" << target;
    vector<int> r = Solution().searchRange(nums, target);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test({5,7,7,8,8,10}, 8);
}

// Result 
//
// 2022-11-15: Runtime 23ms 5.42% Memory 13.7MB 24.3%, https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/843958017/
// 2023-02-17: Runtime 8ms 75.52% Memory 13.7MB 24.19%, https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/899504320/
// 2023-07-25: Runtime 4ms 94.29% Memory 12.92MB 72.39%, https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/450043622/


