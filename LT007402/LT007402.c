#include <lt_help/lt.h>

bool searchMatrix(int** matrix, int r, int c, int target) {
  
    if( r <=0 || c <=0 || matrix == NULL || target < matrix[0][0] || target > matrix[r-1][c-1] )
        return false;
  
    int h,l,m,v;
    h = r-1;
    l = 0;
    
    while( l <= h)
    {
        m = (l+h)/2;
        v = matrix[m][0];
        if ( target > v )
            l = m + 1;
        else if( target < v )
            h = m - 1;
        else
            return true;
    }
    
    int rr = h;
    if( rr < 0 || target > matrix[rr][c-1] )
        return false;
    
    h = c-1;
    l = 0;
    
    while( l <= h)
    {
        m = (l+h)/2;
        v = matrix[rr][m];
        if ( target > v )
            l = m + 1;
        else if( target < v )
            h = m - 1;
        else
            return true;
    }
    
    return false;
}

            
void test(int** matrix, int r, int c, int target)
{
    printf("input: matrix=");
    outputArray2(matrix, r, c);
    printf(", target=%d", target);
    bool rst = searchMatrix(matrix, r, c, target);
    printf("; output: %d\n", rst);
}

int main(void)
{
    int data[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int* matrix[3] = {data[0], data[1], data[2]};
    test(matrix, 3, 4, 13);
}

// Result 
//
// 2022/11/18 
//     Runtime Error