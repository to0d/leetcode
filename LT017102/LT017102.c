#include <lt_help/lt.h>

int titleToNumber(char* s) {
    
    if( s == NULL ) 
        return 0;
    
    int v = 0; 
    char c;
    while( (c=*s++) != '\0' )
        v=v*26+(c-'A'+1);
    
    return v;
}


void test(char* s)
{
    printf("input: %s", s);
    int r = titleToNumber(s);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test("A");
    test("AB");
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 5.4MB 80.28%, https://leetcode.com/problems/excel-sheet-column-number/submissions/847496686/
