#include <lt_help/lt.h>



class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for(int v : nums)
            if( digitOf(v)%2 == 0)
                ++even;
        return even;
    }
    int digitOf(int n)
    {   int d = 0;
        for(; n > 0; n/=10)
            ++d;
        return d;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findNumbers(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({12,345,2,6,7896});
}


// Result 
//
// 2022-12-12: Runtime 5ms 73.29% Memory 10MB 15.6%, https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/858514301/



