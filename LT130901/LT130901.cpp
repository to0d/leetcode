#include <lt_help/lt.h>

class Solution {
public:
    string freqAlphabets(string s) {
        static char buf[1000];
        int buf_len = 0, len = s.length(), pos = 0;
        while( pos < len )
        {   if( (pos+2) < len && isdigit(s.at(pos)) && isdigit(s.at(pos+1)) && s.at(pos+2) == '#' )
            {   int n = std::stoi(s.substr(pos, 2));
                if( n >= 10 && n <= 26 )
                {   buf[buf_len++] = (char)('j'+(n-10));
                    pos += 3;
                    continue;
                }
            }
            buf[buf_len++] = (char)('a' + s.at(pos) - '1');
            ++pos;
        }

        return string(buf, buf_len);
    }
};



void test(string s)
{
    cout << "input: " << s;
    string r = Solution().freqAlphabets(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("10#11#12");
}


// Result 
//
// 2022-12-12: Runtime 3ms 49.55% Memory 6.3MB 58.94%, https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/submissions/858697775/
// 2023-02-24: Runtime 0ms 100% Memory 6.3MB 36.69%, https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/submissions/904206613/



