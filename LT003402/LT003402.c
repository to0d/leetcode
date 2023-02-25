#include <lt_help/lt.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0, h = numsSize-1, a = -1, b = -1, m, v, *r;
    if( nums != NULL && numsSize != 0)
    {   if( numsSize == 1 )
        {   if(*nums == target)
            {   a = 0;
                b = 0;
            }
        }
        else
        {   while( l <= h )
            {   m = (l+h)/2;
                if( (v=nums[m]) == target )
                    break;
                else if( v < target )
                    l = m + 1;
                else
                    h = m - 1;
            }

            if( v == target) 
            {   l = 0; h = m-1;
                while( l <= h )
                {   
                    int m2 = (l+h)/2;
                    if( (v=nums[m2]) >= target )
                        h = m2 - 1;
                    else
                        l = m2 + 1;
                }
                a = h+1;
                l = m+1; h = numsSize-1;
                while( l <= h )
                {   
                    int m2 = (l+h)/2;
                    if( (v=nums[m2]) <= target )
                        l = m2 + 1;
                    else
                        h = m2 - 1;
                }
                b = l-1;
            }
        }
    }

    r = (int*)malloc(sizeof(int)*2);
    r[0] = a; 
    r[1] = b;
    *returnSize = 2;
    return r;
}



void test(int* nums, int numsSize, int target)
{
    printf("input: nums=");  
    outputArray(nums, numsSize);
    printf(", target=%d", target);
    
    int returnSize = 0;
    int *r = searchRange(nums, numsSize, target, &returnSize);
    printf("; output: ");
    outputArray(r, returnSize);
    printf("\n");
}

int main(void)
{
    int nums1[6] = {5,7,7,8,8,10};
    test(nums1, 6, 8);
}

// Result 
//
// 2022-11-15: Runtime 4ms 97.50% Memory 7.3MB 99%, https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/843963148/
// 2023-02-17: Runtime 10ms 56.74% Memory 7.3MB 83.97%, https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/899505997/


