#include <lt_help/lt.h>

// f(n) = max( Vn+f(n-2), f(n-1))
//      = V1                 n = 1
//      = max(V1,V2)         n = 2
// 
// 

int rob(int* nums, int n) {
#define max(x,y) (x)>(y)?(x):(y)
    if( n <= 0 ) return 0;
    if( n == 1 ) return nums[0];
    if( n == 2 ) return max(nums[0],nums[1]);
    
    int a = nums[0], b = max(nums[0],nums[1]);    
    for(int i = 2; i < n; ++i)
    {   int c = max(b, nums[i]+a);
        a = b;
        b = c;
    }
    
    return b;
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
    int num1[5] = {2,7,9,3,1};
    test(num1, 5);
}

// Result 
//
// 2022-11-11: Runtime 6ms 37.81% Memory 5.8MB 81.78%, https://leetcode.com/problems/house-robber/submissions/842996525/
// 2023-02-20: Runtime 0ms 100% Memory 6MB 42.11%, https://leetcode.com/problems/house-robber/submissions/901596709/



