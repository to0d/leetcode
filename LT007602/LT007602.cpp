#include <lt_help/lt.h>

class Solution {
public:
    string minWindow(string s, string t) {
        int hited[256] = {0}, used[256] = {0}, tgtNum = 0;
        for(char c : t)
        {   if( used[c]++ == 0 )
                tgtNum++;
        }

        const char* s1 = s.c_str(), *s2 = s.c_str(), *minPos = NULL;
        int num = 0, minLen = 0;
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
        
        return string(minPos, minLen);
    }
};


void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t; 
    string r = Solution().minWindow(s, t);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("ADOBECODEBANC", "ABC");
}

// Result 
//
// 2022-11-19: Runtime 9ms 48% Memory 6.4MB 93.33%, https://leetcode.com/problems/minimum-window-substring/submissions/846162877/
// 2023-02-18: Runtime 8ms 95.43% Memory 7.35MB 98.56%, https://leetcode.cn/problems/minimum-window-substring/submissions/451890199/



