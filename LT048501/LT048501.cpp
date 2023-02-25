#include <lt_help/lt.h>



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int _max = 0, last = 0;        
        for(int n : nums)
        {   if( n == 1 )
            {   if( ++last > _max)
                    _max = last;
            }
            else
                last = 0;
        }
        return _max;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findMaxConsecutiveOnes(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,1,0,1,1,1});
}


// Result 
//
// 2023-01-09: Runtime 35ms 89.11% Memory 36.1MB 73.2%, https://leetcode.com/problems/max-consecutive-ones/submissions/874782485/


