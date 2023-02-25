#include <lt_help/lt.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> ms;
        for( char c : s )
        {   if( c == '(' || c == '{' || c == '[' )
                ms.push(c);
            else if( ms.empty() || ms.top() != _expect(c))
                return false;
            else
                ms.pop();
        }

        return ms.empty();
    }
    
    char _expect(char c) {
        switch(c)
        {
          case ')': return '(';
          case '}': return '{';
          case ']': return '[';
          default : return 0;
        }
    }
};


void test(string s)
{
    cout << "input: " << s;  
    bool r = Solution().isValid(s);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test("()[]{}");
}

// Result 
//
// 2022-11-05: Runtime 0ms 100% Memory 6.4MB 54.81%, https://leetcode.com/problems/valid-parentheses/submissions/837375904/
// 2023-02-15: Runtime 0ms 100% Memory 6.2MB 81.51%, https://leetcode.com/problems/valid-parentheses/submissions/898559501/



