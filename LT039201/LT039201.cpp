#include <lt_help/lt.h>

class Solution {
public:

    bool isSubsequence(string s, string t) {
        const char* a = s.c_str();
        const char* b = t.c_str();
        
        while( *a != '\0')
        {
            while(*b != '\0' && *b != *a)
                ++b;

            if( *b != *a )
                return false;

            ++a;
            ++b;
        }

        return *a == '\0';
    }
};



void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t;
    bool r = Solution().isSubsequence(s, t);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("aaaaaa", "bbaaaa");
}

// Result 
//
// 2022-11-25: Runtime 7ms 10.1% Memory 6.3MB 73.76%, https://leetcode.com/problems/is-subsequence/submissions/849478030/
// 2023-02-21: Runtime 0ms 100% Memory 6.4MB 29.80%, https://leetcode.com/problems/is-subsequence/submissions/901945760/



