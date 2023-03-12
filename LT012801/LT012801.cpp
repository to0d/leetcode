#include <lt_help/lt.h>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(begin(nums), end(nums));
        int _max = 0, last = INT_MIN, count = 0;
        for(int num : nums)
        {   if( num == (last+1))
                ++count;
            else if( num != last)
            {   _max  = max(_max, count);
                count = 1;
            }
            last = num;
        }
        return max(_max, count);
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().longestConsecutive(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({100,4,200,1,3,2});
}


// Result 
//
// 2023-03-13: Runtime 68ms 96.71% Memory 33.7MB 98.70%, https://leetcode.com/problems/longest-consecutive-sequence/submissions/913898719/

