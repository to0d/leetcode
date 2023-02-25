#include <stdio.h>
#include <stdlib.h>

// f(m,n) = f(m-1,n) + f(m,n-1)
// f(m,n) = f(n,m)
// f(1,n) = 1
int uniquePaths(int m, int n) {
    if( m == 0 || n == 0 ) 
        return 0;
    if( m < n )  
        return uniquePaths(n, m);
    if( n == 1 ) 
        return 1;

#define MAX_NUM 100
    static int unique_nums[MAX_NUM][MAX_NUM] = {0};
    int num = unique_nums[m-1][n-1];
    if( num == 0 )
        num = uniquePaths(m-1,n)+uniquePaths(m,n-1);

    unique_nums[m-1][n-1] = num;
    return num;
}



void test(int m, int n)
{
    printf("input: m=%d, n=%d", m, n);
    int r = uniquePaths(m, n);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(3, 7);
    test(10, 10);
}

// Result 
//
// 2023-02-10: Runtime 0ms 100% Memory 5.7MB 16.70%, https://leetcode.com/problems/unique-paths/submissions/895397901/
// 2023-02-18: Runtime 0ms 100% Memory 5.6MB 55.87%, https://leetcode.com/problems/unique-paths/submissions/900073502/
