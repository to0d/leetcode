#include <lt_help/lt.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int k = m + n - 1, i = m - 1, j = n - 1;
    while( j >= 0 )
    {   if( i >= 0 && nums1[i] > nums2[j] )
        {   nums1[k--] = nums1[i--];   
        }
        else
        {   nums1[k--] = nums2[j--];
        }
    }
}

void test(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    printf("input: nums1="); 
    outputArray(nums1, nums1Size);
    printf(", m=%d, nums2=", m); 
    outputArray(nums2, nums2Size);    
    printf(", n=%d; output: ", n);
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    outputArray(nums1, nums1Size);
    printf("\n");
}

int main(void)
{
    int nums1[6]= {1,2,3,0,0,0};
    int nums2[3]= {2,5,6};
    test(nums1, 6, 3, nums2, 3, 3);
}

// Result 
//
// 2022-11-06: Runtime 6ms 44.72% Memory 6MB 98.74%, https://leetcode.com/problems/merge-sorted-array/submissions/855109300/

