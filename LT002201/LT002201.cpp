#include <lt_help/lt.h>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        string str;
        makeParenthesis(n, n, rst, str);
        return rst;
    }
    
    void makeParenthesis(int left, int right, vector<string>& rst, string& str){
        if( left > 0 )
        {   str.push_back('(');
            makeParenthesis(left-1, right, rst, str);
            str.pop_back();
        }

        if( right > 0 && left < right )
        {   str.push_back(')');
            makeParenthesis(left, right-1, rst, str);
            str.pop_back();
        }

        if( left == 0 && right == 0)
            rst.push_back(str);
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


