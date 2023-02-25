#include <lt_help/lt.h>

int findComplement(int num) {
    int mask = 1;
    for( int t = num>> 1; t != 0 ; t >>= 1 )
        mask = mask<<1|1;
    //printf("num=%d, mast=%d\n", num, mask);
    return mask & ~num;
}


void test(int num)
{
    printf("input: %d", num);
    int r = findComplement(num);
    printf("; output: %d\n", r);
}

int main(void)
{
    test(5);
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 5.6MB 34.17%, https://leetcode.com/problems/number-complement/submissions/846390539/
