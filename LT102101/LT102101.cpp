#include <lt_help/lt.h>



class Solution {
public:
    string removeOuterParentheses(string s) {
        static char stack[100000];
        int deep = 0, num = 0, len = s.length();
        for(int i = 0; i < len ; ++i )
        {   char c = s.at(i);
            if( c == '(' )
            {   if( deep++ > 0 )
                    stack[num++] = c;
            }
            else // ')'
            {    if( --deep > 0 )
                    stack[num++] = c;
            }
        }
        return string(stack, num);
    }
};

void test(string s)
{
    cout << "input: " << s;
    string r = Solution().removeOuterParentheses(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("(()())(())");
}


// Result 
//
// 2022-12-08: Runtime 0ms 100% Memory 6.7MB 54.64%, https://leetcode.com/problems/remove-outermost-parentheses/submissions/856179603/



