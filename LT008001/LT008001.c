#include <lt_help/lt.h>

int removeDuplicates(int* nums, int size) {
    
    if( size == 0)
        return 0;
    
    int *pstart = nums + 1;
    int *pend  = nums+size;
    int *pLast = nums;
    int  c = 1;
    
    while( pstart < pend )
    {
        if( *pstart != *pLast )
        {
            if( c > 1 )
                *(pLast+1) = *pLast++;
            
            if( ++pLast != pstart ) 
                *pLast = *pstart;
            
            c = 1;
        }
        else
            ++c;
        
        ++pstart;
    }
    
    if( c > 1 )
        *(pLast+1) = *pLast++;
    
    return pLast - nums + 1;   
}


void test(int* nums, int size)
{
    printf("input: ");
    outputArray(nums, size);
    int r = removeDuplicates(nums, size);
    printf("; output: ");
    outputArray(nums, r);
    printf("\n");
}

int main(void)
{
    int nums[6] = {1,1,1,2,2,3};
    test(nums, 6);
}

// Result 
//
// 2022/11/23
// Wrong Answer
//      Input
//      [0,0,1,1,1,1,2,3,3]
//      Output
//      [0,0,0,1,1,2,3,3]
//      Expected
//      [0,0,1,1,2,3,3]