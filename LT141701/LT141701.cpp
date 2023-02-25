#include <lt_help/lt.h>

class Solution {
public:
    string reformat(string s) {
        static char buf[500];
        int len = s.length(), al = 0, nl = 0;
        for(int i = 0;i < len ; ++i)
        {   char c = s.at(i);
            if( _type(c) == 0 )
                buf[len- ++nl] = c;
            else
                buf[al++] = c;
        }

        if( std::abs(al-nl) > 1)
            return "";

        static char buf2[500];  // optimize, can use only one buffer - 2022/12/14 @TODO 
        int buf_len = 0, pos1 = 0, pos2 = len - nl;
        if( al < nl )
            buf2[buf_len++] = buf[pos2++];
        
        while( pos2 < len )
        {   buf2[buf_len++] = buf[pos1++];
            buf2[buf_len++] = buf[pos2++];
        }
        
        if( pos1 < al )
            buf2[buf_len++] = buf[pos1++];
   
        return string(buf2, buf_len);
    }

    static int _type(char c) {  
        return c >= '0' && c <= '9' ? 0 : 1;
    }
};



void test(string s)
{
    cout << "input: " << s;
    string r = Solution().reformat(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("a0b1c2");
}


// Result 
//
// 2022-12-14: Runtime 8ms 36.40% Memory 7.1MB 90.79%, https://leetcode.com/problems/reformat-the-string/submissions/859468029/
// 2023-02-25: Runtime 4ms 72.83% Memory 7.2MB 90.55%, https://leetcode.com/problems/reformat-the-string/submissions/904214846/




