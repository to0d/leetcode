#include <lt_help/lt.h>

int trailingZeroes(int n) {
    return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
}



void test(int n)
{
    printf("input: %d", n);
    int r = trailingZeroes(n);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(3);
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 5.6MB 22.97%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/847498754/
// 2023-02-22: Runtime 0ms 100% Memory 5.4MB 98.70%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/902643430/
