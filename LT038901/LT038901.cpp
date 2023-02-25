#include <lt_help/lt.h>

class Solution {
public:
    char findTheDifference(string s, string t) {
        const char *ps = s.c_str(), *pt = t.c_str();
        int sc[256] = {0}, tc[256] = {0};
        
        for(; *ps != '\0'; ++ps)
            sc[(int)*ps]++;

        for(; *pt != '\0'; ++pt)
            tc[(int)*pt]++;

        for(int i = 0; i < 256; ++i )
            if( sc[i] != tc[i] )
                return (char) i;

        return 0;
    }
};



void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t;
    char r = Solution().findTheDifference(s, t);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("abcd", "abcde");
}

// Result 
//
// 2022-11-22: Runtime 6ms 33.66% Memory 5.6MB 99.51%, https://leetcode.com/problems/find-the-difference/submissions/847779663/
// 2023-02-21: Runtime 0ms 100% Memory 6.7MB 74.78%, https://leetcode.com/problems/find-the-difference/submissions/901949577/


