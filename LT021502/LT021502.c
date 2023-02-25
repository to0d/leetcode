#include <lt_help/lt.h>


int findKthLargest(int* nums, int n, int k) {

    int target = nums[0];
    
    // find the largest number
    if( k == 1 )
    {   for( int i = 1; i < n; ++i )
        {   if( nums[i] > target )
                target = nums[i];
        }
        return target;
    }
    
    // find the smallest number
    if( k == n )
    {   for( int i = 1; i < n; ++i )
        {   if( nums[i] < target )
                target = nums[i];
        }
        return target;
    }
    
    int low = 1, high = n-1;
    while( low <= high )
    {   
        if( nums[low] >= target )
        {   ++low;
            continue;
        }
        
        if( nums[high] < target )
        {   --high;
            continue;
        }
        
        int t = nums[low];
        nums[low] = nums[high];
        nums[high] = t;
    }
    
    // a[0]  ...................
    //  1                 high low
    int largeNumber = high;
    
    if( k <= largeNumber )
    {   return findKthLargest(nums+1, largeNumber, k);
    } 
    else if( k == (largeNumber+1) )
    {   return target;        
    }   
    else
    {   return findKthLargest(nums+low, n - high - 1, k-largeNumber-1);
    }
}


void test(int* nums, int n, int k)
{
    printf("input: nums=");
    outputArray(nums, n);
    printf(", k=%d", k);
    int r = findKthLargest(nums, n, k);
    printf("; output: %d;\n", r);
}

int main(void)
{
    int nums[6] = {3,2,1,5,6,4};
    test(nums, 6, 2);
}

// Result 
//
// 2022-11-21: Runtime 135ms 49.63% Memory 11.2MB 91.24%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/847520326/

