#include <lt_help/lt.h>


// xxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//          |<-a->|<-b->|<-c->|    
// |<--          len       -->|
//  num[0..a-1] + num[a..a+b-1] = [a+b..a+b+c-1]
//     a+b+c <= len
//     a <= c
//     b <= c  ==> c <= len/2, b <= (len - c) /2, 
bool dfs_is_add_num( const char* start, int lb, int lc, int len){
    if( lc > len/2 || lb > len/2) 
        return false;

    const char* pc = start + len - 1;
    const char* pb = pc - lc;
    const char* pa = pb - lb;
    int i, v, la;
    char c;
    bool aEnd;

    if( (*(pb+1) == '0' && lc > 1) )
        return false;
    
    if( (*(pa+1) == '0' && lb > 1) )
        return false;
    
    for (i=0,v=0,la=0,aEnd=false; i < lb || i < lc || v != 0; v /= 10, ++i)
    {
        if( !aEnd )  
        {   if( pa >= start)
            {   v += *pa-- - '0';
                ++la;
            }
            else
                aEnd = true;
        }
        
        if( i < lb ) 
            v += *pb-- - '0';
TRY2:
        c = '0' + v % 10;
        if( i >= lc)
            return false;
        
        if( *pc-- != c )
        {
            if( !aEnd && la > 1)
            {   v -= *(++pa) - '0';
                ++pc;
                --la;
                aEnd = true;
                goto TRY2;
            }
            
            return false;
        }
    }
    
    while( *(++pa) == '0' && la > 1)
        --la;
    
    return pa == start || dfs_is_add_num( start, la, lb, len - lc);
}

bool isAdditiveNumber(char* num) {
    if( num == NULL ) 
        return false;
 
    int len = strlen(num);
    for(int lc = len /2; lc > 0; --lc )
        for(int lb = len - lc - 1; lb > 0; --lb)
            if( dfs_is_add_num( num, lb, lc, len))
                return true;
    
    return false;
}


void test(char* num)
{
    printf("input: %s", num);
    int r = isAdditiveNumber(num);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test("112358");
    test("199100199");
}

// Result 
//
// 2022-11-22: Runtime 0ms 100% Memory 5.7MB 20%, https://leetcode.com/problems/additive-number/submissions/847768993/
// 2023-02-22: Runtime 0ms 100% Memory 5.7MB 60%, https://leetcode.com/problems/additive-number/submissions/902742030/


