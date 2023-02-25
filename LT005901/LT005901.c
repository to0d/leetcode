#include <lt_help/lt.h>

int calculate(int m, int n, int x, int y)
{
#define min(x,y) (x)<(y)?(x):(y)
    int s, val;
    int x2 = n - x - 1;
    int y2 = m - y - 1;
    int dx = min(x2,x);
    int dy = min(y2,y);
    
    int z = min(dx,dy);
    if( z > 0 )
        s = 2*(m+n)*z - 4*z*z;
    else
        s = 0;

    // up layer
    if( z == y || z == x2 )
        val = s + x + y - 2*z ;
    else
        val = s - x - y + 2*(m+n-2)-6*z;

    return val;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    int ** matrix = (int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; ++i)
    {
        (*returnColumnSizes)[i] = n;
        int* row = (int*)malloc(sizeof(int)*n);
        for(int j=0; j<n; ++j)
            row[j]=calculate(n,n,j,i)+1;
        
        matrix[i] = row;
    }

    return matrix;
}



void test(int n)
{
    printf("input: %d; output: arr=", n);
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int** r = generateMatrix(n, &returnSize, &returnColumnSizes);
    outputArray2(r, n, n);
    printf(", returnSize=%d, returnColumnSizes=", returnSize);
    outputArray(returnColumnSizes, returnSize);
    printf("\n");
}

int main(void)
{
    test(3);
}

// Result 
//
// 2022-11-16: Runtime 11ms 5.88% Memory 6.5MB 36.76%, https://leetcode.com/problems/spiral-matrix-ii/submissions/844279862/
// 2023-02-17: Runtime 3ms 71.79% Memory 6.5MB 38.46%, https://leetcode.com/problems/spiral-matrix-ii/submissions/899829078/

