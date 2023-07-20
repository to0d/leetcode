#include <lt_help/lt.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.length() == 0 )
            return 0;
        
        int idx_map[256] = {0};
        int len = s.length(), max_len = 0, last = 0;
        
        for(int i = 0; i < len; ++i)
        {   char c = s.at(i);
            int idx = idx_map[c];
            if( idx > last)
            {   max_len = std::max(max_len, i - last);
                last = idx;
            }
            idx_map[c] = i + 1;            
        }
        return std::max(max_len, len - last);
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
// 2023-07-20: Runtime 4 ms 97.17% Memory 6.7 MB 92.18%, https://leetcode.cn/submissions/detail/448576825/



