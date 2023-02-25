#include <lt_help/lt.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;
        _find(res, digits, str, 0);     
        return res;
    }
    
    void _find(vector<string>& res, string& digits, string& str, int i){
                                        //   0   1      2      3      4      5      6       7      8       9
        static char* num_chars[10]      = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        static int   num_char_count[10] = {  1,  0,     3,      3,     3,    3,     3,      4,     3,      4};

        if( i == (int) digits.size())
        {   if(!str.empty())
                res.push_back(str);
            return;
        }
        
        int digit = digits[i] - '0';
        int num_count = num_char_count[digit];        
        if( num_count == 0 )
        {   _find(res, digits, str, i + 1);
            return;
        }
        
        const char* nchars = num_chars[digit];      
        for( int j = 0; j < num_count; ++j )
        {
            str.push_back( nchars[j]);
            _find(res, digits, str, i + 1);
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



