#include <lt_help/lt.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for( char c : s ) {
            char c2 = 0;
            switch(c){ 
                case ')': c2  = '(';  break;
                case ']': c2  = '[';  break;
                case '}': c2  = '{';  break;
                default : st.push(c); break; 
            }
            if( c2 == 0 )
                continue;
            if(st.size() == 0 || st.top() != c2) 
                return false;
            st.pop();
        }
        return st.size() == 0;
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
// 2023-03-14: Runtime 0ms 100% Memory 6.4MB 11.86%, https://leetcode.com/problems/valid-parentheses/submissions/914461609/
// 2023-09-23: Runtime 0ms 100% Memory 6.35MB 7.60%, https://leetcode.cn/problems/valid-parentheses/submissions/468971257/



