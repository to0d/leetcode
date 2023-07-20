#include <lt_help/lt.h>

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), begin = 0, end = 1;
        for( int i = 1; i < len; ++i )
        {   for( int j = 0; j < 2; j++)
            {   int d  = (end+1)/2;
                int lx = i - d;
                int ly = (j == 0 ? (i + d - 1) : (i + d)); // even or odd sequence
                if( lx < 0 || ly >= len )
                    continue;

                int llx = lx, lly = ly;
                for(; llx < lly && s[llx] == s[lly]; ++llx, --lly);

                if( llx < lly )
                    continue;
                
                begin = lx, end = ly - lx + 1;                
                for(; --lx >= 0 && ++ly < len && s[lx] == s[ly]; --begin, end+=2 );
            }
        }
        return s.substr(begin, end);
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
// 2023-03-11: Runtime 11ms 91.51% Memory 7MB 75.25%, https://leetcode.com/problems/longest-palindromic-substring/submissions/913012417/
// 2023-07-20: Runtime 8 ms 97.01% Memory 6.8 MB 79.62%, https://leetcode.cn/submissions/detail/448583974/
