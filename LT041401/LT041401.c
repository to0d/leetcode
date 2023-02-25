#include <lt_help/lt.h>

int thirdMax(int* nums, int n) {

    int max[3];
    int count = 0;
    for( int i = 0; i < n; ++i)
    {   int v = nums[i];
        for( int j = 0 ; j < 3; ++j)
        {   
            if( j >= count )
            {   max[count++] = v;
                break;
            }
            
            if( v > max[j] )
            {   int t = max[j];
                max[j] = v;
                v = t;
            }
            else if( v == max[j] )
            {   break;
            }
        }
    }
    
    return count == 3 ? max[2]:max[0];
}


void test(int* nums, int n)
{
    printf("input: ");
    outputArray(nums, n);
    int r = thirdMax(nums, n);
    printf("; output: %d\n", r);
}

int main(void)
{
    int nums[3] = {3,2,1};
    test(nums, 3);
}

// Result 
//
// 2022-11-21: Runtime 4ms 82.61% Memory 6.1MB 96.27%, https://leetcode.com/problems/third-maximum-number/submissions/846975714/

