#include <lt_help/lt.h>

// shrink numsSize firstly to avoid copy too much 'zero'
// for example: 
// 	[1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,]
void moveZeroes(int* nums, int numsSize) {
    int i = 0, k = numsSize - 1;
    while( k >=0 && nums[k] == 0 )
        --k;

    while( i <= k && nums[i] != 0)
        ++i;

    int j = i++;    
    for(; i <= k; ++i )
        if( nums[i] != 0 )
            nums[j++] = nums[i];

    while( j <= k )
        nums[j++] = 0;
}



void test(int* nums, int numsSize)
{
    printf("input: "); 
    outputArray(nums, numsSize);
    moveZeroes(nums, numsSize);
    printf("; output: ");
    outputArray(nums, numsSize);
    printf("\n");
}

int main(void)
{
    int nums[5] = {0,1,0,3,12};
    test(nums, 5);
}

// Result 
//
// 2022-11-19: Runtime 109ms 36.85% Memory 15MB 80.11%, https://leetcode.com/problems/move-zeroes/submissions/846315428/
// 2023-02-22: Runtime 98ms 37.89% Memory 15.3MB 38.81%, https://leetcode.com/problems/move-zeroes/submissions/902732880/


