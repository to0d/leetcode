#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    
    if( num >= 4000 || num == 0)
        return "";
    
    static char RomanNum[4][2] = {
        { 'I','V' },    // I: 1,   V: 5
        { 'X','L' },    // X: 10,  L: 50 
        { 'C','D' },    // C: 100, D: 500
        { 'M','-' }     // M: 1000
    };

    int stack[4] = {0};
    int deep = 0;
    while( num > 0 )
    {   stack[deep++] = num % 10;
        num /= 10;        
    }
    
    static char buf[256] = {0};
    int len = 0;
    for(; deep > 0; --deep )
    {        
        char c1 = RomanNum[deep-1][0];
        char c5 = RomanNum[deep-1][1];
        
        int val = stack[deep-1];
        switch(val)
        {
        case 0:  break;
        case 1:  buf[len++] = c1; break;
        case 2:  buf[len++] = c1; buf[len++] = c1; break;
        case 3:  buf[len++] = c1; buf[len++] = c1; buf[len++] = c1; break;
        case 4:  buf[len++] = c1; buf[len++] = c5; break;
        case 5:  buf[len++] = c5; break;
        case 6:  buf[len++] = c5; buf[len++] = c1; break;
        case 7:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; break;
        case 8:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; buf[len++] = c1; break;
        case 9:  buf[len++] = c1; buf[len++] = RomanNum[deep][0]; break;
        }
    }

    char* rst = (char*) malloc(len+1);
    memcpy(rst, buf, len);
    rst[len] = '\0';

    return rst;
}

void test(int num)
{
    printf("input: %d", num);
    char* r = intToRoman(num);
    printf("; output: %s\n", r);
}

int main(void)
{
    test(1994);
}

// Result 
//
// 2022-11-02: Runtime 11ms 30.97% Memory 5.9MB 82.52%, https://leetcode.com/problems/integer-to-roman/submissions/835433306/
// 2023-02-15: Runtime 9ms 40.62% Memory 5.8MB 81.97%, https://leetcode.com/problems/integer-to-roman/submissions/898523992/
