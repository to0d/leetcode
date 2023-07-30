#include <lt_help/lt.h>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length() )
            return false;
        vector<int> cmap(26, 0);
        for(char c : s )
            cmap[c- 'a']++;
        for(char c : t )
            if( --cmap[c- 'a'] < 0 )
                return false;
        return true;
    }
};



void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t << "; output: "; 
    bool r = Solution().isAnagram(s, t);
    cout << r << ";" << endl;
}

int main(void)
{
    test("anagram", "nagaram");
    test("rat", "car");
}

// Result 
//
// 2022-11-19: Runtime 30ms 6.80% Memory 7.4MB 62.7%, https://leetcode.com/problems/valid-anagram/submissions/846317857/
// 2023-02-22: Runtime 12ms 58.42% Memory 7.3MB 62.9%, https://leetcode.com/problems/valid-anagram/submissions/902727646/
// 2023-07-30: Runtime 4ms 92.39% Memory 6.94MB 71.94%, https://leetcode.cn/problems/valid-anagram/submissions/451497299/

