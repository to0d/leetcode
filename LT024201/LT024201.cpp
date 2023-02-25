#include <lt_help/lt.h>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size()) 
            return false;

        char sx(0), tx(0);
        for( char sc : s )
            sx ^= sc;
        for( char tc : t )
            tx ^= tc;
        
        if( sx != tx )
            return false;
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;
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

