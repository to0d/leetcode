#include <lt_help/lt.h>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size(); 
        if( size == 0) 
            return -1;
        if( size == 1) 
            return nums[0] == target ? 0 : -1;

        int h = size - 1, l = 0;
        while( l <= h )
        {   int m = (l+h)/2;
            int v = nums[m];
            if( v == target )
                 return m;

            if( m == l )
            {   l = m + 1;
                continue;
            }
                            
            if( nums[l] > nums[h] )
            {   if( v < nums[h] )
                {   if( target >= nums[l] )
                        h = m - 1;
                    else if( target > nums[h] )
                        return -1;
                    else if( target >= v )
                        l = m + 1;
                    else 
                        h = m - 1;
                }
                else
                {   if( target >= v )
                        l = m + 1;
                    else if( target >= nums[l] )
                        h = m - 1;
                    else if( target > nums[h])
                        return -1;
                    else if( target == nums[h])
                        return h;
                    else
                        l = m + 1;
                }
            }
            else
            {   if( v < target )
                     l = m + 1;
                else 
                     h = m - 1;
            }
        }
        
        return -1;
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", target=" << target;
    int r = Solution().search(nums, target);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({4,5,6,7,0,1,2}, 0);
}

// Result 
//
// 2022-11-15: Runtime 8ms 22.37% Memory 11.1MB 80.99%, https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/843952872/
// 2023-02-17: Runtime 3ms 82.65% Memory 11.2MB 42.72%, https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/899502696/


