#include <lt_help/lt.h>

int removeElement(int* nums, int num, int val) {
    int i = 0; 
    for( int j =0; j < num; ++j )
    {   if( j < num && nums[j] != val )
        {   if( i != j )
                nums[i] = nums[j];
            ++i; 
        }
    }
    return i;
}



void test(int* nums, int size, int val)
{
    printf("input: nums=");
    outputArray(nums, size);
    printf(", val=%d", val);
    int r = removeElement(nums, size, val);
    printf("; output: ");
    outputArray(nums, r);
    printf("\n");
}

int main(void)
{
    int num1[4] = {3,2,2,3};
    test(num1, 4, 3);
}

// Result 
//
// 2022-11-15: Runtime 0ms 100% Memory 6.1MB 48.55%, https://leetcode.com/problems/remove-element/submissions/843936976/
// 2023-02-16: Runtime 0ms 100% Memory 6.2MB 10.73%, https://leetcode.com/problems/remove-element/submissions/899191212/
