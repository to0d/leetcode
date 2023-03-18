#include <lt_help/lt.h>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if( len2 == 0 )
            return 0;

        for(int i=0; i<=len1-len2; ++i)
        {   int j = 0;
            while( j<len2 && haystack.at(i+j)==needle.at(j))
                ++j;
            if( j==len2 )
                return i;
        }

        return -1;
    }
};


void test(string haystack, string needle)
{
    cout << "input: haystack=" << haystack << ", needle=" << needle;
    int r = Solution().strStr(haystack, needle);
    cout << "; output: " << r << endl;
}


int main(void)
{
    test("sadbutsad", "sad");
}

// Result 
//
// 2023-02-10: Runtime 4ms 38.10% Memory 6.2MB 70.86%, https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/895360238/

