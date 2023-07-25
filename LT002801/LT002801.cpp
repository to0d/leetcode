#include <lt_help/lt.h>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        for(int i = 0, j=0; i <= (len1 - len2); ++i, j=0)
        {   while(j < len2 && haystack[i+j] == needle[j] )
                ++j;
            if( j == len2 )
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
// 2023-07-25: Runtime 0ms 100% Memory 5.84MB 99.00%, https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/450034351


