#include <lt_help/lt.h>

class Solution {
public:
    bool isPalindrome(string s) {
        return isPalindrome(s.c_str(), 0, s.size() - 1);
    }
    
    bool isPalindrome(const char* s, int low, int high) {
        while( low < high )
        {   if( !isalnum(s[low]) )
                ++low;
            else if( !isalnum(s[high]) )
                --high;
            else 
            {   if( tolower(s[low]) != tolower(s[high]))
                return false;
                ++low;
                --high;  
            }                
        }
        return true;
    }
};



void test(string s)
{
    cout << "input: " << s;
    bool r = Solution().isPalindrome(s);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test("A man, a plan, a canal: Panama");
}

// Result 
//
// 2022-11-21: Runtime 20ms 10.80% Memory 7.4MB 60.22%, https://leetcode.com/problems/valid-palindrome/submissions/847469030/
// 2023-02-22: Runtime 10ms 32.15% Memory 7.5MB 60.61%, https://leetcode.com/problems/valid-palindrome/submissions/902640371/
// 2023-03-11: Runtime 0ms 100% Memory 7.3MB 84.87%, https://leetcode.com/problems/valid-palindrome/submissions/912992181/



