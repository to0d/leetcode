#include <lt_help/lt.h>



class Solution {
public:
    int longestPalindrome(string s) {
        int size = s.size();
        int cm[256] = {0};        
        
        for(int i = 0; i < size; ++i)
            cm[((int)s.at(i))]++;
        
        int odd = 0;
        int count = 0;
        
        for(int i = 0; i < 256; ++i)
        {
            int n = cm[i];
            if( n == 0 )
                continue;
            if ( n%2 == 0 )
                count += n;
            else
            {   count += n-1;
                ++odd;
            }
        }

        if( odd > 0 )
            count ++;
        return count;
    }
};


void test(string s)
{
    cout << "input: " << s << "; output: ";
    int r = Solution().longestPalindrome(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("abccccdd");
    test("ccc");
}

// Result 
//
// 2022-11-25: Runtime 0ms 100% Memory 6.6MB 86.17%, https://leetcode.com/problems/longest-palindrome/submissions/849511416/
