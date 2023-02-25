#include <lt_help/lt.h>

void rotate(int* nums, int n, int k) {
    if( k >= n ) return rotate(nums, n, k%n);
    if( k <= 0 || n <= 1 ) return;

    int m, s2, k2; 
    if( n>k*2 )
    {   m  = k;
        s2 = k; 
        k2 = k;
    }
    else
    {   m  = n - k;
        s2 = 0; 
        k2 = n-m*2;
    } 
    
    for(int i=0; i<m; ++i )
    {   int t = nums[n-m+i];
        nums[n-m+i] = nums[i];
        nums[i] = t;
    }
    
    rotate(nums+s2, n-m, k2);
}



void test(int* nums, int n, int k)
{
    printf("input: nums=");  
    outputArray(nums, n);
    printf(", k=%d", k); 
    rotate(nums, n, k);
    printf("; output: ");
    outputArray(nums, n);
    printf(";\n");
}

int main(void)
{
    int num1[7] = {1,2,3,4,5,6,7};
    test(num1, 7, 3);
}

// Result 
//
// 2022-11-19: Runtime 234ms 10.32% Memory 22.1MB 72.65%, https://leetcode.com/problems/rotate-array/submissions/846350682/
// 2023-02-22: Runtime 145ms 11.75% Memory 21.9MB 100%, https://leetcode.com/problems/rotate-array/submissions/902645021/


