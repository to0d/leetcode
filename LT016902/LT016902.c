#include <lt_help/lt.h>

int _cmpInt (const void *e1, const void *e2 )
{   return *((int*)e1) - *((int*)e2);
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), _cmpInt);
    return nums[numsSize/2];
}



void test(int* nums, int numsSize)
{
    printf("input: ");
    outputArray(nums, numsSize);
    int r = majorityElement(nums, numsSize);
    printf("; output: %d;\n", r);
}

int main(void)
{
    int nums[3] = {3,2,3};
    test(nums, 3);
}

// Result 
//
// 2022-11-21: Runtime 31ms 18.84% Memory 8.1MB 17.11%, https://leetcode.com/problems/majority-element/submissions/847493904/
// 2023-02-20: Runtime 19ms 86.48% Memory 8.1MB 21.81%, https://leetcode.com/problems/majority-element/submissions/901598857/
