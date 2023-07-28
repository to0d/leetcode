#include <lt_help/lt.h>

class Solution {
public:
    int trailingZeroes(int n) {
        int val = 0;
        while( n > 0 )             // Assume: 1. the number of '2' is bigger than the number of '5'
        {   n /= 5;                //         2. The number of '0' in n! is equal to the number of '5'
            val += n;              // 
        }
        return val;
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().trailingZeroes(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3);
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 4ms 37.14% Memory 5.9MB 64.11%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/847497994/
// 2023-02-22: Runtime 0ms 100% Memory 6MB 64.20%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/902642620/
// 2023-07-28: Runtime 0ms 100% Memory 5.66MB 55.10%, https://leetcode.cn/problems/factorial-trailing-zeroes/submissions/451139162/
