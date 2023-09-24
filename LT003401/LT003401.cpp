#include <lt_help/lt.h>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size(), l = 0, h = len-1;
        int find = biRange_equal(nums, l, h, target);
        if( find == -1 )
            return {-1, -1};
        int left = biRange_blow(nums, 0, h, target) + 1;
        int right = biRange_high(nums, l, len-1, target) - 1;
        return {left, right};
    }
    
    int biRange_high(vector<int>& nums, int l, int h, int target) {
        while( l <= h ){
            int m = (l+h)/2;
            int v = nums[m];
            if( v <= target )
                l = m + 1;
            else 
                h = m - 1;
        }
        return l;
    }
    
    int biRange_blow(vector<int>& nums, int l, int h, int target) {
        while( l <= h ){
            int m = (l+h)/2;
            int v = nums[m];
            if( v >= target )
                h = m - 1;
            else
                l = m + 1;
        }
        return h;
    }
    
    int biRange_equal(vector<int>& nums, int& l, int& h, int target) {
        while( l <= h ){
            int m = (l+h)/2;
            int v = nums[m];
            if( v == target )
                return m;
            else if( v < target )
                l = m + 1;
            else 
                h = m - 1;
        }
        return -1;
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
// 2023-09-24: Runtime 8ms 66.19% Memory 13.35MB 7.39%, https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/469168657/


