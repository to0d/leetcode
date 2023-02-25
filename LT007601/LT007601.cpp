#include <lt_help/lt.h>

class Solution {
public:
    string minWindow(string s, string t) {
        if( t.size() == 0 || s.size() < t.size() )
            return "";
        else if( t.size() == 1 )
        {   char c = t[0];
            for( char cc : s)
            {   if( cc == c)
                    return t;
            }
            return "";
        }

        int target[256] = {0}, hit[256] = {0};
        int prev = 0, pos = 0, srcSize = s.size(), targetCount = 0;
        for( char c : t )
        {   if( target[c]++ == 0)
                ++targetCount;
        }

        // find first match
        int hitCount = 0;
        for( ;hitCount < targetCount && pos < srcSize; ++pos)
        {    char c = s[pos];
             if( target[c] > 0 && ++hit[c] == target[c] )
                hitCount++;
        }

        if( hitCount < targetCount)
            return "";

        int minPrev = 0, minSize = INT_MAX;
        while( pos <= srcSize )
        {   for(; prev < pos; ++prev )
            {   char pc = s[prev];
                int& hc = hit[pc];
                if( hc > 0 )
                {   if( hc == target[pc])
                        break;
                    --hc;
                }
            }
            
            int len = pos - prev;
            if( len < minSize )
            {   minSize = len;
                minPrev = prev;
            }

            if( pos == srcSize)
                break;
            
            char pc = s[prev], nc = 0;
            while( pc != nc && pos < srcSize)
            {   nc = s[pos++];
                if( target[nc] > 0 )
                    ++hit[nc];
            }
        }

        return s.substr(minPrev, minSize);
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
// 2022-11-19: Runtime 27ms 60.62% Memory 7.6MB 99.53%, https://leetcode.com/problems/minimum-window-substring/submissions/846161635/
// 2023-02-18: Runtime 7ms 95.24% Memory 7.7MB 98.57%, https://leetcode.com/problems/minimum-window-substring/submissions/900097634/


