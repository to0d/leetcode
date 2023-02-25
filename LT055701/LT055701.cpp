#include <lt_help/lt.h>

class Solution {
public:
    string reverseWords(string s) {
        static char buf[50000];
        int len = s.length(), pos = 0, buf_len = 0;
        while( pos < len )
        {   if( s.at(pos) == ' ' )
            {   buf[buf_len++] = ' ';
                ++pos;
                continue;
            }

            int pos2 = pos;
            for(; pos2 < len; ++pos2)
                if( s.at(pos2) == ' ')
                    break;
            
            for(int i = pos2 - 1; i >= pos; --i)
                buf[buf_len++] = s.at(i);

            pos = pos2;
        }
        
        return string(buf, buf_len);
    }
};



void test(string s)
{
    cout << "input: " << s << "; output:";
    string r = Solution().reverseWords(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("God Ding");
}

// Result 
//
// 2022-11-19: Runtime 6ms 84.69% Memory 6.9MB 90.23%, https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/846385138/
// 2023-02-24: Runtime 7ms 98.26% Memory 10.3MB 41.26%, https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/904170037/
