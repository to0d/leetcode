#include <lt_help/lt.h>

class Solution {
public:
    string reverseOnlyLetters(string s) {
        static char buf[100];
        int pos1 = 0, pos2 = s.length()-1;
        
        while( pos1 <= pos2 )
        {   if(!isEnglishChar(s.at(pos1)))
                buf[pos1++] = s.at(pos1);
            else if(!isEnglishChar(s.at(pos2)))
                buf[pos2--] = s.at(pos2);
            else if(pos1 == pos2)
                buf[pos1++] = s.at(pos1);
            else
            {   buf[pos1] = s.at(pos2);
                buf[pos2] = s.at(pos1);
                ++pos1;
                --pos2;
            }
        }

        return string(buf, s.length());
    }

    static bool isEnglishChar(char c){   
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};



void test(string s)
{
    cout << "input: " << s;
    string r = Solution().reverseOnlyLetters(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("ab-cd");
}


// Result 
//
// 2022-12-04: Runtime 4ms 29.49% Memory 6.1MB 73.23%, https://leetcode.com/problems/reverse-only-letters/submissions/854367126/
// 2023-02-18: Runtime 0ms 100% Memory 6.1MB 28.78%, https://leetcode.com/problems/reverse-only-letters/submissions/900120390/


