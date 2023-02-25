#include <lt_help/lt.h>

bool isAnagram(char* s, char* t) {
    if( s == NULL || t == NULL ) 
        return false;
    
    int heap[26] = {0}, slen = 0, tlen = 0;
    char c;
    while( (c=*s++) != '\0' )
    {   heap[c-'a']++;
        slen++;
    }

    while( (c=*t++) != '\0' )
    {   if( --(heap[c-'a']) < 0 )
            return false;
        ++tlen;
    }

    return slen == tlen;
}



void test(const char* s, const char* t)
{
    printf("input: s=%s, t=%s", s, t); 
    bool r = isAnagram(makeString(s), makeString(t));
    printf("; output: %d\n", r);
}

int main(void)
{
    test("anagram", "nagaram");
    test("rat", "car");
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 6MB 38.28%, https://leetcode.com/problems/valid-anagram/submissions/846318974/
// 2023-02-22: Runtime 3ms 74.44% Memory 5.8MB 98.76%, https://leetcode.com/problems/valid-anagram/submissions/902728798/

