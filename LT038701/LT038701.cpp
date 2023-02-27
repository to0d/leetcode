#include <lt_help/lt.h>

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        int count[256] = {0};
        for(int i = 0; i < len; ++i)
            count[(int)s.at(i)]++; 
        
        for(int i = 0; i < len; ++i)
            if( count[(int)s.at(i)] == 1 )
                return i;
        
        return -1;
    }
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().firstUniqChar(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("loveleetcode");
}

// Result 
//
// 2022-11-22: Runtime 19ms 36.5% Memory 7.1MB 32.11%, https://leetcode.com/problems/first-unique-character-in-a-string/submissions/847778542/
// 2023-02-27: Runtime 14ms 98.65% Memory 10.6MB 93.29%, https://leetcode.com/problems/first-unique-character-in-a-string/submissions/905734112/


