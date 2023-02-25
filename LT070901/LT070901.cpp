#include <lt_help/lt.h>



class Solution {
public:
    string toLowerCase(string s) {
        static short diff = 'a' - 'A';
        static char buf[100];
        int len = s.length();
        int update = 0;
        for(int i = 0; i < len; ++i)
        {   char c = s.at(i);
            if( c >= 'A' and c <= 'Z' )
            {   c += diff;
                ++update;
            }
            buf[i] = c;
        }
        return update == 0 ? s : string(buf, len);
    }
};


void test(string s)
{
    cout << "input: " << s;
    string r = Solution().toLowerCase(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("Hello");
}


// Result 
//
// 2022-12-02: Runtime 0ms 100% Memory 6.2MB 63.65%, https://leetcode.com/problems/to-lower-case/submissions/853253908/

