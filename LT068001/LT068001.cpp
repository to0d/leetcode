#include <lt_help/lt.h>

class Solution {
public:
    bool validPalindrome(string s) {     
        int low = 0, high = s.length() - 1, tmp_low, tmp_high;
        if( _validPalindrome(s, low, high) || (low+1) == high)
            return true;
        if( s[low+1] == s[high] && _validPalindrome(s, (tmp_low=(low+1)), (tmp_high=high)))
            return true;
        if( s[low] == s[high-1] && _validPalindrome(s, (tmp_low=low), (tmp_high=(high-1))))
            return true;
        return false;
    }

    bool _validPalindrome(string& s, int& low, int& high){   
        for (; low < high; ++low, --high)
            if( s[low] != s[high] )
                return false;
        return true;
    }
};



void test(string s)
{
    cout << "input: " << s;
    bool r = Solution().validPalindrome(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("abca");
}


// Result 
//
// 2022-12-01: Runtime 223ms 5.9% Memory 19.6MB 91.36%, https://leetcode.com/problems/valid-palindrome-ii/submissions/852618345/
// 2023-02-24: Runtime 46ms 94.82% Memory 19.7MB 64.12%, https://leetcode.com/problems/valid-palindrome-ii/submissions/904187399/
// 2023-03-11: Runtime 39ms 99.18% Memory 19.6MB 85.30%, https://leetcode.com/problems/valid-palindrome-ii/submissions/913009019/


