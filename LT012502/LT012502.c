#include <lt_help/lt.h>

bool isPalindrome(char* s) {
    int len = 0;
    if( s == NULL || (len=strlen(s)) == 0 ) return true;
    
    char* p = s; 
    char* q = s + len - 1;
    
    while( p < q )
    {   
        if( !isalnum(*p) ) { ++p; continue; }
        if( !isalnum(*q) ) { --q; continue; }
        if( tolower(*p) != tolower(*q) ) return false;
        ++p;
        --q;
    }
    
    return true;
}


void test(const char* s)
{
    printf("input: %s", s);
    bool r = isPalindrome(makeString(s));
    printf("; output: %d\n;", r);
}

int main(void)
{
    test("A man, a plan, a canal: Panama");
}

// Result 
//
// 2022-11-21: Runtime 3ms 77.20% Memory 6.4MB 37.9%, https://leetcode.com/problems/valid-palindrome/submissions/847470669/
