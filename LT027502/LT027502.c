#include <lt_help/lt.h>


int hIndex(int* citations, int n) {
    if( n == 0 ) 
        return 0;
   
    int l = 0, h = n-1;
    while( l <=h )
    {   int m = (h+l)/2;
        int d = n-1-m - citations[m];
        if( d > 0 )
            l = m+1;
        else if( d < 0 )
            h = m-1;
        else
            return n-1-m;
    }

    return n-1-h;
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
    int citations[5] = {0,1,3,5,6};
    test(citations, 5);
}

// Result 
//
// 2022-11-11: Runtime 38ms 12.12% Memory 9.5MB 48.48%, https://leetcode.com/problems/h-index-ii/submissions/847759506/
// 2023-02-22: Runtime 23ms 29.3% Memory 9.6MB 32.26%, https://leetcode.com/problems/h-index-ii/submissions/902731430/

