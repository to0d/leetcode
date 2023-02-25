#include <lt_help/lt.h>

bool findCanJump(int* nums, int n, int i){
    int jmp = nums[i];
    if( (i+jmp) >= (n-1) )   return true;
    if( jmp == 0 ) return false;
    for(; jmp > 0 ; --jmp )
    {   if(findCanJump(nums, n, i+jmp))
        {   return true;
        }
    }
    nums[i] = 0;
    return false;
}

bool canJump(int* nums, int n) {
    int i;
    if( n == 0 || nums == NULL )
        return false;

    for(i=n-2; i >=0 && (n-i-1) > nums[i]; --i)
        nums[i] = 0;

    return findCanJump(nums, n, 0);
}



void test(int* nums, int n)
{
    printf("input: matrix=");
    outputArray(nums, n);
    bool r = canJump(nums, n);
    printf("; output: %d\n", r);
}

int main(void)
{
    int nums[5] = {2,3,1,1,4};
    test(nums, 5);
}

// Result 
//
// 2022-11-19: Runtime 128ms 23.32% Memory 9.1MB 13.11%, https://leetcode.com/problems/jump-game/submissions/846139842/
// 2023-02-17: Runtime 76ms 33.80% Memory 8.8MB 13.46%, https://leetcode.com/problems/jump-game/submissions/899821009/


