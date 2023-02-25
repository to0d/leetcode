#include <lt_help/lt.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (; n!= 0; n &= (n-1))
            ++sum;
        return sum;
    }
};



void test(uint32_t n)
{
    cout << "input: " << n;
    int r = Solution().hammingWeight(n);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(11);
}

// Result 
//
// 2022-11-19: Runtime 5ms 30.22% Memory 6MB 74.55%, https://leetcode.com/problems/number-of-1-bits/submissions/846361080/
// 2023-02-22: Runtime 0ms 100% Memory 6MB 36.23%, https://leetcode.com/problems/number-of-1-bits/submissions/902627502/
