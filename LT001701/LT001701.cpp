#include <lt_help/lt.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits == "" ) return {};
        vector<string> res;
        string str;
        _find(res, digits, str);     
        return res;
    }
    
    void _find(vector<string>& res, string& digits, string& str){
        static string letters [10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if( str.length() ==  digits.size())
        {   res.push_back(str);
            return;
        }

        string& letter = letters[digits[str.length()] - '0'];
        for( int i = 0; i < letter.length(); ++i)
        {   str.push_back( letter.at(i) );
            _find(res, digits, str);
            str.pop_back();
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



