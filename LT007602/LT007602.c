#include <lt_help/lt.h>

char* minWindow(char* s, char* t) {
    int hited[256] = {0}, used[256] = {0}, tgtNum = 0;
    for( ; *t != 0; ++t )
    {   if( used[*t]++ == 0 )
            tgtNum++;
    }

    char* s1 = s, *s2 = s;
    int num = 0, minLen = 0;
    char* minPos = NULL;
    while( *s2 != 0 || ( *s1 !=0 && num == tgtNum ) )
    {   if( num < tgtNum )
        {   if( used[*s2] && ++hited[*s2] == used[*s2] )
                ++num;
            ++s2;
        }
        else if( num == tgtNum )
        {   int len = s2 - s1;
            if( minLen == 0 || len < minLen )
            {   minLen = len;
                minPos = s1;
            }
            if( used[*s1] && --hited[*s1] < used[*s1] )
                --num;
            ++s1;
        }
    }

    if( minPos == NULL )
        return "";
    
    char* minWin = malloc(minLen+1);
    memcpy(minWin, minPos, minLen);
    minWin[minLen] = 0;
    return minWin;
}


           
void test(const char* s, const char* t)
{
    printf("input: s=%s, t=%s", s, t);
    char* r = minWindow(makeString(s), makeString(t));
    printf("; output: %s\n", r);
}

int main(void)
{
    test("ADOBECODEBANC", "ABC");
}

// Result 
//
// 2022-11-19: Runtime 9ms 48% Memory 6.4MB 93.33%, https://leetcode.com/problems/minimum-window-substring/submissions/846162877/
// 2023-02-18: Runtime 5ms 69.14% Memory 6.4MB 95.6%, https://leetcode.com/problems/minimum-window-substring/submissions/900098314/



