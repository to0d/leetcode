#include <lt_help/lt.h>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        static char buf[16];
        vector<string> rst;
        _generateParenthesis(rst, buf, 0, n, n);
        return rst;
    }
    
    void _generateParenthesis(vector<string>& rst, char* buf, int len, int left, int right) {
        if( left == 0 && right == 0 ){
            rst.push_back(string(buf, len));
            return;
        }
        if( left > 0 ){
            buf[len] = '(';
            _generateParenthesis(rst, buf, len+1, left-1, right);
        }
        if( left < right ){
            buf[len] = ')';
            _generateParenthesis(rst, buf, len+1, left, right-1);
        }
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<string> r = Solution().generateParenthesis(n);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test(3);
}

// Result 
//
// 2022-11-05: Runtime 4ms 66.14% Memory 11.4MB 87.16%, https://leetcode.com/problems/generate-parentheses/submissions/837410154/
// 2023-02-16: Runtime 0ms 100% Memory 11.6MB 78.22%, https://leetcode.com/problems/generate-parentheses/submissions/899167716/
// 2023-09-23: Runtime 0ms 100% Memory 11.12MB 56.60%, https://leetcode.cn/problems/generate-parentheses/submissions/468974184/


