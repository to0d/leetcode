#include <lt_help/lt.h>

class Solution {
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int findHigh = -1, findLow = -1;
        if( nums.size() > 0 && target >= nums[0] && target <= nums[nums.size() - 1] )
            find(nums, target, 0, nums.size() - 1, findLow, findHigh);
        return {findLow, findHigh};
    }
    
    void find(vector<int> &nums, int target, int low, int high, int &findLow, int &findHigh){   
        while(low >=0 && low <= high && (findHigh == -1 || findLow == -1))
        {   if( findHigh == -1 && nums[high] == target)
                findHigh = high;
            else if( findLow == -1 && nums[low] == target)
                findLow = low;         
            else
            {   int m = ( high + low ) / 2;
                int v = nums[m] ;
                if( v > target )
                    high = m - 1;
                else if( v < target )
                    low = m + 1;
                else
                {
                    if( findHigh == -1)
                    {   int findLow2 = m;
                        find(nums, target, m + 1, high, findLow2, findHigh);
                        if( findHigh == -1 )
                            findHigh = m;
                    }
                    
                    if( findLow == -1)
                    {   int findHigh2 = m;
                        find(nums, target, low, m - 1, findLow, findHigh2);
                        if( findLow == -1 )
                            findLow = m;
                    }
                }
            }
        }  
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


