#include <lt_help/lt.h>

char* countAndSay(int n) 
{
#define MAX_LEN_COUNT   1024*32
    char temp[MAX_LEN_COUNT*2];
    temp[0] = '1';
    char *src = temp, *dst = temp + MAX_LEN_COUNT;
    int len = 1, i;

    while( --n >= 1 )
    {   char last = *src;
        int count = 1, dst_len = 0;
        for( i=1,count=1; i<len; ++i )
        {   if( last == *(src+i) )
            {   ++count;
                continue;
            }

            dst_len+= sprintf(dst+dst_len,"%d",count);
            dst[dst_len++] = last;
            last = *(src+i);
            count = 1;
        }
        
        dst_len+= sprintf(dst+dst_len,"%d",count);
        dst[dst_len++] = last;
        len = dst_len;

        char* tmp = dst;
        dst = src;
        src = tmp;
    }
    
    char* result = malloc(len+1);
    memcpy(result, src, len);
    result[len] = '\0';
    return result;
}



void test(int n)
{
    printf("input: %d", n);
    char* r = countAndSay(n);
    printf("; output: %s\n", r);
}

int main(void)
{
    test(1);
    test(4);
}

// Result 
//
// 2022-11-16: Runtime 6ms 42.71% Memory 6.4MB 59.38%, https://leetcode.com/problems/count-and-say/submissions/844552945/
// 2023-02-17: Runtime 3ms 60% Memory 6.3MB 60%, https://leetcode.com/problems/count-and-say/submissions/899509857/


