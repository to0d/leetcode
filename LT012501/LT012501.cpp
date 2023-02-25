#include <lt_help/lt.h>

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        if( size <= 1 ) 
            return true;
        
        int p1 = 0, p2 = size - 1, step = 0;
        while( p1 <= p2 )
        {   if( step == 0 )
            {   if( isalnum(s[p1]) )
                    step++;
                else
                    ++p1;
            }
            else if( step == 1 )
            {   if( isalnum(s[p2]) )
                    step++;
                else
                    --p2;    
            }
            else 
            {   if( tolower(s[p1]) != tolower(s[p2]))
                    return false;
                ++p1;
                --p2;
                step = 0;
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



