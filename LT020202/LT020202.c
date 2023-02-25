#include <lt_help/lt.h>

// 2147483647
// 1999999999 ==> 1*1+9*9*9 = 730 

static int HappyValue[1000] = {0}; // 1 : is
                                   // 2 : not
                                   // 3 : circle

bool isHappy(int n) {
    
    if( n <= 0 ) return false;
    if( n == 1 ) return true;
    
    int v = 0;
    if( n < 1000 )
    {   v = HappyValue[n];
    }
    
    switch(v)
    { 
    case 1: return true;
    case 2: return false;
    case 3: 
        if( n < 1000 )
            HappyValue[n] = 2;
        return false;
    default: // 0
        break;
    }

    if( n < 1000 )
        HappyValue[n] = 3;
    int n2 = 0;
    int t, x;
    
    for( t=n; t>0; t/= 10 )
    {   x = t%10;
        n2 += x*x;
    }
    
    bool r = isHappy(n2);
    
    if( n < 1000 )
        HappyValue[n] = r ? 1 : 2;
    return r;
}

void test(int n)
{
    int rc = (int)isHappy(n);    
    printf("input: %d; output: %d;\n", n, rc);
}


int main(void)
{
    test(19); 
    test(1999999999); 
}

// Result 
//
// 2022-11-21: Runtime 2ms 49.73% Memory 5.6MB 57.29%, https://leetcode.com/problems/happy-number/submissions/846972847/

