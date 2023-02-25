#include <lt_help/lt.h>

#define max(x,y) (x)>(y)?(x):(y)

int rob_in_line(int* nums, int n) {
    
    if( n <= 0 ) return 0;
    if( n == 1 ) return nums[0];
    if( n == 2 ) return max(nums[0],nums[1]);

    int a = nums[0];
    int b = max(nums[0],nums[1]);
    int c, i;

    for( i = 2; i < n; ++i)
    {
        c = max(b, nums[i]+a);
        a = b;
        b = c;
    }

    return b;
}

int rob(int* nums, int n) {
    
    if( n <= 0 ) return 0;
    if( n == 1 ) return nums[0];
    if( n == 2 ) return max(nums[0],nums[1]);
    if( n == 3 ) return max(nums[0],max(nums[1],nums[2]));
    
    int a = nums[0] + rob_in_line(nums+2, n-3);
    int b = rob_in_line(nums+1, n-1);
    
    return max(a,b);
}
            
void test(int* nums, int n)
{
    int output = rob(nums, n);
    printf("input: ");  
    outputArray(nums, n);
    printf("; output: %d\n", output);
}

int main(void)
{
    int num1[3] = {2,3,2};
    test(num1, 3);
}

// Result 
//
// 2022-11-14: Runtime 0ms 100% Memory 5.8MB 66.67%, https://leetcode.com/problems/house-robber-ii/submissions/842999389/


