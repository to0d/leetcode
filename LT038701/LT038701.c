#include <lt_help/lt.h>


int firstUniqChar(char* s) {
    
    int count[256] = {0};
    char c, *p;
    for( p = s; (c=*p) != '\0'; ++p)
    {   count[(int)c]++;           
    }
    
    for( p = s; (c=*p) != '\0'; ++p)
    {   if( count[(int)c] == 1 )
        {   return p - s;
        }        
    }
    
    return -1;
}


void test(char* s)
{
    printf("input: %s", s);
    int r = firstUniqChar(s);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test("loveleetcode");
}

// Result 
//
// 2022-11-22: Runtime 19ms 36.5% Memory 7.1MB 32.11%, https://leetcode.com/problems/first-unique-character-in-a-string/submissions/847778542/
