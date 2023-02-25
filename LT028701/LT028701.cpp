#include <lt_help/lt.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
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
                        if(m == -1 || m == last_number )
                            return last_number;
                        last_number = m;
                        m = -1;
                    }
                }
            }
        }
        return -1;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findDuplicate(nums);
    cout << "; output: " << r << endl;
}


int main(void)
{
    test({1,3,4,2,2});
}

// Result 
//
// 2023-02-17: Runtime 113ms 83.7% Memory 61.3MB 34.89%, https://leetcode.com/problems/find-the-duplicate-number/submissions/899788372/
