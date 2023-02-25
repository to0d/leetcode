#include <lt_help/lt.h>


int _cmpInt (const void *e1, const void *e2 )
{   return *((int*)e2) - *((int*)e1);
}
            
int nextGreaterElement(int n) {
    
    int buf[16] = {0};
    int len, last, tmp, i, pos, minv;
    int MUL_OVER = INT_MAX/10;
    
    for( last=-1, len=0; n > 0; n/= 10, last = buf[len++])
    {   buf[len] = n%10;
        if( buf[len] < last )
        { 
            for( i=0, pos=-1, minv=INT_MAX; i < len; ++i )
            {   if( buf[i] > buf[len] && buf[i]< minv )
                {   pos = i;
                    minv = buf[i];
                }
            }
            
            buf[pos] = buf[len];
            buf[len] = minv;
            qsort(buf, len, sizeof(int), _cmpInt);
            n/= 10;
            for(len++; len > 0; --len )
            {
                if( n > MUL_OVER ) // over flow
                    return -1;
                
                n *= 10;
                n += buf[len-1];
            }
            return n;
        }
    }
    
    return -1;
}



void test(int n)
{
    printf("input: %d", n);
    int r = nextGreaterElement(n);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(12);
}

// Result 
//
// 2022/11/22
//      Runtime Error   2147483486
