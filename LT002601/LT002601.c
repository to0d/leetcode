#include <lt_help/lt.h>

int removeDuplicates(int* nums, int size) {
    if( size <= 1)
        return size;

    int pos1 = 0;
    for(int pos2 = 1; pos2 < size; ++pos2 )
    {   if( nums[pos1] != nums[pos2] )
        {   if( ++pos1 != pos2)
                nums[pos1] = nums[pos2];
        }
    }

    return pos1 + 1;   
}



void test(int* nums, int size)
{
    printf("input: ");  
    outputArray(nums, size);
    int r = removeDuplicates(nums, size);
    printf("; output: %d\n", r);
}

int main(void)
{
    int num1[10] = {0,0,1,1,1,2,2,3,3,4};
    test(num1, 10);
}

// Result 
//
// 2022-11-14: Runtime 6ms 32.2% Memory 7.6MB 12.23%, https://leetcode.com/problems/swap-nodes-in-pairs/submissions/838727024/
// 2023-02-16: Runtime 12ms 82.39% Memory 7.5MB 78.42%, https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/899187502/


