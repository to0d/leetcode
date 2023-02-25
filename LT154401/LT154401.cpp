#include <lt_help/lt.h>



class Solution {
public:
    string makeGood(string s) {
        static char buf[100];
        int buf_len = 0, len = s.length();
        for(int i = 0;i < len; ++i)
        {   char c = s.at(i);
            if( buf_len > 0 && isBad(c, buf[buf_len-1]))
                buf_len--;
            else
                buf[buf_len++] = c;
        }
        return string(buf, buf_len);
    }

    bool isBad(char c1, char c2)
    {   return isupper(c1) != isupper(c2) && toupper(c1) == toupper(c2);
    }
};


void test(string s)
{
    cout << "input: " << s;
    string r = Solution().makeGood(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("leEeetcode");
}


// Result 
//
// 2022-12-15: Runtime 2ms 70.48% Memory 6.1MB 99.24%, https://leetcode.com/problems/make-the-string-great/submissions/859964108/



