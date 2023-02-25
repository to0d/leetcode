#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if( s == NULL || len == 0 )
        return s;
    
    int maxPos = 0, maxWth = 1;
    
    for( int i = 1; i < len; ++i )
    {
        for( int j = 0; j < 2; j++)
        {
            int lx, ly, d = (maxWth+1)/2;
            if( j == 0 ) // check even sequence
            {   lx = i - d;
                ly = i + d - 1;
            }
            else // check odd sequence
            {   lx = i - d;
                ly = i + d;
            }
            
            if( lx < 0 || ly >= len )
                continue;
            
            int llx = lx, lly = ly;
            while(llx < lly && s[llx] == s[lly])
            {   ++llx;
                --lly;
            }
            
            if(llx < lly)
                continue;
            
            maxPos = lx;
            maxWth = ly - lx + 1;
            while( --lx >= 0 && ++ly < len && s[lx] == s[ly] )
            {   --maxPos;
                maxWth += 2;
            } 
        } 
    }
    
    char* rst = (char*) malloc(maxWth + 1);
    memcpy(rst, s + maxPos, maxWth);
    rst[maxWth] = '\0';
    return rst;
}

void test(char* s)
{
    printf("input: %s", s);
    char* r = longestPalindrome(s);
    printf("; output: %s\n", r);
}

int main(void)
{
    test("babad");
}

// Result 
//
// 2023-02-08: Runtime 8ms 91.32% Memory 6MB 88.66%, https://leetcode.com/problems/longest-palindromic-substring/submissions/894124861/
