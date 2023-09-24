#include <lt_help/lt.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, idx = 1, last = 0;
        int idx_map[256] = {0};
        for( auto c : s )
        {   last = std::max(last, idx_map[c]);
            max_len = std::max(max_len, idx - last);
            idx_map[c] = idx++;
        }
        return max_len;
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
// 2023-09-23: Runtime 8 ms 91.14% Memory 6.86 MB 87.07%, https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/468890816/



