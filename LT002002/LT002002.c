#include <lt_help/lt.h>
 
bool isValid(char* s) 
{
    if( s == NULL || *s == '\0' )
        return true;

    char stack[10000];
    int pos = 0;
    char c;
    
    while( (c=*s++) != '\0' )
    {
        char c2;
        switch(c)
        {
        case '(':
        case '[':
        case '{':
            stack[pos++] = c;
            continue; // continue while
        case ')': c2 = '('; break;
        case ']': c2 = '['; break;
        case '}': c2 = '{'; break;
        default:
            return false;
        }
        
        if( pos == 0 || stack[pos-1] != c2 )
            return false;
        
        --pos;
    }
    
    return pos == 0;
}


void test(const char* s)
{
    printf("input: %s; output: ", s);
    bool out = isValid(makeString(s));
    printf("%d\n", out);;
}


int main(void)
{
    test("()[]{}");
}

// Result 
//
// 2022-11-05: Runtime 0ms 100% Memory 5.6MB 62.22%, https://leetcode.com/problems/valid-parentheses/submissions/837386863/
// 2023-02-15: Runtime 0ms 100% Memory 5.6MB 82.62%, https://leetcode.com/problems/valid-parentheses/submissions/898561448/

