#include <lt_help/lt.h>

class Solution {
public:
    string reverseWords(string s) {
        static char buf[10000];
        int len = s.length();
        memcpy(buf, s.c_str(), len);

        veserseString(buf, 0, len-1);

        int ls = 0, le = 0;
        for(int i = 0; i < len; ++i)
        {   if( buf[i] == ' ')
            {   if( le != ls )
                {   veserseString(buf, ls, le-1);
                    buf[le] = ' ';
                    ls = le + 1;
                    le = ls;
                }
            }
            else
                buf[le++] = buf[i];
        }
        
        veserseString(buf, ls, le-1);

        if( le < len )
            buf[le] = '\0';
        
        while( buf[--le] == ' ' )
            buf[le] = '\0';

        return string(buf, le+1);
    }

    void veserseString(char* s, int start, int end)
    {   for(; start < end ;  ++start, --end)
        {   int c = s[start];
            s[start] = s[end];
            s[end] = c;    
        }
    }
};



void test(string s)
{
    cout << "input: " << s;
    string r = Solution().reverseWords(s); 
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("the sky is blue");
}

// Result 
//
// 2022-11-19: Runtime 4ms 46.34% Memory 6.2MB 91.46%, https://leetcode.com/problems/reverse-words-in-a-string/submissions/846367099/
// 2023-02-22: Runtime 0ms 100% Memory 7.2MB 78.55%, https://leetcode.com/problems/reverse-words-in-a-string/submissions/902663882/



