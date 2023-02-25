#include <lt_help/lt.h>



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.size() == 0 )
            return 0;

        int b[256]  = {0};
        int last = 0, maxLen = 0, size = s.size();

        for(int i = 0; i < size ; ++i)
        {   char c = s[i];
            int idx = b[c];
            if( idx > last )
            {   maxLen = std::max((i-last), maxLen);
                last = idx;
                //cout << "i=" << i << ", maxLen=" << maxLen << ", last=" << last << endl;
            }
            b[c] = i+1;
        }

        return std::max((size - last), maxLen);
    }
};


void test(string s)
{
    cout << "input: " << s;
    int r = Solution().lengthOfLongestSubstring(s);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test("abcabcbb");
}

// Result 
//
// 2023-02-06: Runtime 7ms 92.71% Memory 7MB 92.60%, https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/892658509/



