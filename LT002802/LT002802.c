#include <lt_help/lt.h>

int* makeNext(char *p){
    int len = strlen(p);
    int *next = (int*) malloc(sizeof(int)*len);
    memset(next, 0, sizeof(int)*len);
    next[0] = -1;
    
    int k = -1, j = 0;
    while( j < (len-1) )
    {   if( k == -1 || p[j] == p[k] )
            next[++j] = ++k;
        else
            k = next[k];
    }

    return next;
}

//KMP algorithm
int strStr(char* s, char* t) {
    int len_t = strlen(t);
    if(len_t == 0)
        return 0;
    
    int len_s = strlen(s);
    if(len_s == 0)
        return -1;

    int *next = makeNext(t);
    int i = 0, j = 0; 
    
    while( i < len_s && j != len_t)
    {   if( j == -1 || s[i] == t[j] )
        {   ++i;
            ++j;
        }
        else
            j = next[j];
    }

    free(next);
    return j == len_t ? i - len_t : -1;
}


            
void test(const char* s, const char* t)
{
    printf("input: s=%s, t=%s", s, t);
    int r = strStr(makeString(s), makeString(t));
    printf("; output: %d\n", r);
}

int main(void)
{
    test("sadbutsad", "sad");
}

// Result 
//
// 2022-11-15: Runtime 0ms 100% Memory 5.8MB 21.47%, https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/843943471/
// 2023-02-16: Runtime 0ms 100% Memory 5.6MB 68.91%, https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/899195330/



