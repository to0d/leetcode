#include <lt_help/lt.h>


int hIndex(int* citations, int size) {

#define min(a,b) (a)<(b)?(a):(b)

    int i,sum;
    int papers[1024*64] = {0};
    
    for( i=0; i<size; ++i )
        papers[min(citations[i],size)]++;

    for(sum=0, i = size; i > 0; --i)
    {   sum += papers[i];
        if( i <= sum )
            break;
    }
    return i;
}


void test(int* citations, int size)
{
    printf("input: ");
    outputArray(citations, size); 
    int r = hIndex(citations, size);
    printf("; output: %d;\n", r);
}

int main(void)
{
    int citations[5] = {3,0,6,1,5};
    test(citations, 5);
}

// Result 
//
// 2022-11-19: Runtime 2ms 76.60% Memory 6.4MB 17.2%, https://leetcode.com/problems/h-index/submissions/847527789/
