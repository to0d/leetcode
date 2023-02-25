#include <lt_help/lt.h>

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        static char buf1[200], buf2[200];
        int len1 = _input(buf1, s);
        int len2 = _input(buf2, t);
        if( len1 != len2 )
            return false;
        
        for(int i = 0; i < len1; ++i)
            if( buf1[i] != buf2[i] )
                return false;

        return true;
    }

    static int _input(char* buf, string s){ 
        int len = s.length(), count = 0;
        for(int i = 0;i < len; ++i)
        {   char c = s.at(i);
            if( c != '#' )
                buf[count++] = c;
            else if (count > 0)
                --count;
        }
        return count;
    }
};



void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t;
    bool r = Solution().backspaceCompare(s, t);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("ab#c", "ad#c");
}


// Result 
//
// 2022-12-04: Runtime 3ms 43.9% Memory 6.3MB 77.31%, https://leetcode.com/problems/backspace-string-compare/submissions/854180303/
// 2023-02-24: Runtime 0ms 100% Memory 6.4MB 50.7%, https://leetcode.com/problems/backspace-string-compare/submissions/904195186/



