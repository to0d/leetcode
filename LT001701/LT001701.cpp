#include <lt_help/lt.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits == "" ) 
            return {};
        vector<string> rst;
        char buf[5];
        _letterCombinations(rst, digits, 0, buf);
        return std::move(rst);
    }
    
    void _letterCombinations(vector<string>& rst, string& digits, int idx, char* buf) {
        static vector<string> lm = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if( idx == digits.length() )
            rst.push_back(string(buf, idx));
        else 
            for(char c : lm[digits[idx]-'0'] ) {
                buf[idx] = c;
                _letterCombinations(rst, digits, idx+1, buf);
            }
    }
};


void test(string digits)
{
    cout << "input: " << digits;
    vector<string> r = Solution().letterCombinations(digits);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test("23");
}

// Result 
//
// 2022-11-03: Runtime 4ms 34.73% Memory 6.4MB 94.39%, https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/836078016/
// 2023-02-15: Runtime 3ms 40.34% Memory 6.4MB 94.37%, https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/898551886/
// 2023-03-13: Runtime 0ms 100% Memory 6.4MB 81.89%, https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/914457141/
// 2023-09-23: Runtime 0ms 100% Memory 6.75MB 6.50%, https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/468962984/




