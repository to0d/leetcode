#include <lt_help/lt.h>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for( int& n : nums )
            if( n <= 0 )
                n = 0;

        int size = nums.size();
        for(int i = 0 ; i < size; ++i )
        {   int& n = nums[i];
            if( n > 0)
            {   if( n == (i + 1) )
                    n = -1;
                else
                {   int last_number = n;
                    n = 0;
                    while( last_number > 0 && last_number <= size )
                    {   int& m = nums[last_number - 1];
                        last_number = m;
                        m = -1;
                    }                   
                }          
            }
        }

        int pos = 0;
        while( pos < size && nums[pos] == -1 )
            ++pos;    
        
        return pos + 1;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    cout << "; output: ";
    int r = Solution().firstMissingPositive(nums);
    cout << r << ";" << endl;
}

int main(void)
{
    test({3,4,-1,1});
}

// Result 
//
// 2022-11-16: Runtime 56ms 54.68% Memory 31.4MB 55.26%, https://leetcode.com/problems/first-missing-positive/submissions/844571494/
// 2023-02-17: Runtime 47ms 82.14% Memory 31.4MB 85.63%, https://leetcode.com/problems/first-missing-positive/submissions/899776387/


