#include <lt_help/lt.h>



class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if( len == 0 )
            return s;

        int maxPos = 0, maxWth = 1;

        for( int i = 1; i < len; ++i )
        {
            for( int j = 0; j < 2; j++)
            {                
                int d  = (maxWth+1)/2;
                int lx = i - d;
                int ly = (j == 0 ? (i + d - 1) : (i + d)); // even or odd sequence

                if( lx < 0 || ly >= len )
                    continue;
                
                int llx = lx, lly = ly;
                while(llx < lly && s[llx] == s[lly])
                {   ++llx;
                    --lly;
                }

                if(llx < lly)
                    continue;
                
                maxPos = lx;
                maxWth = ly - lx + 1;
                while( --lx >= 0 && ++ly < len && s[lx] == s[ly] )
                {   --maxPos;
                    maxWth += 2;
                } 
            }
        }

        return s.substr(maxPos, maxWth);
    }
};

void test(string s)
{
    cout << "input: " << s;    
    string r = Solution().longestPalindrome(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("babad");
}

// Result 
//
// 2023-02-08: Runtime 7ms 96.3% Memory 7MB 66.61%, https://leetcode.com/problems/longest-palindromic-substring/submissions/894121714/
