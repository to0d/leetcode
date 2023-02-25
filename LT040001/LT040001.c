#include <lt_help/lt.h>

int _getn(int m)
{
    int v = 1;
    for(int i = 0;i < m; ++i)
        v *= 10;
    return v;
}

int _findn(int n, int m)
{   // printf("n=%d, m=%d\n", n,m );
    
    if( m == 1 )
        return n;
    
    int v = _getn(m-1)*m;
    int d = (n-1)/v;
    
    if( (n-1) % m == 0 )
    {   return d + 1;       
    }
    
    n -= d*v;
    n -= n/m;    
    
    return _findn( n-1, m-1); 
}

int findNthDigit(int n) {
    if( n <= 9 )
        return n;
    
    int m = 1;
    int ms = 9;
    while( n > ms )
    {   n -= ms;
        ++m;
        ms = _getn(m-1)*9*m; // m=3: ms=9*10^2*3
    }
    
    //printf("ms=%d\n", ms);
    return _findn(n, m);
}


void test(int n)
{
    printf("input: %d", n);
    int r = findNthDigit(n);
    printf("; output: %d\n", r);
}

int main(void)
{
    test(3);
    test(11);
}

// Result 
//
// 2022/11/21
//      Wrong Answer
//      Input
//      10000
//      Output
//      8
//      Expected
//      7