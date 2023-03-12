#include <lt_help/lt.h>

class Solution {
public:
    int countSubstrings(string s) {
        palind_cached = vector<int>(s.length()*s.length(), -1);
        int count = 0, len = s.length();
        for(int i = 0;i < len; ++i )
            for(int j = i;j < len; ++j)
                if(isPalindrome(s, i, j))
                   count++;  
        return count;
    }
       
    bool isPalindrome(string& s, int low, int high){
        int len = s.length();
        if( low < 0 || high >= len || low > high)
            return true;
        int idx = len * low + high;
        int palind = palind_cached[idx];
        if( palind == -1 )
        {   palind = 0;
            if( s[low] == s[high] && isPalindrome(s, low+1, high-1))
                palind = 1;
            palind_cached[idx] = palind;
        }
        return palind == 1;
    }
    vector<int> palind_cached;
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().countSubstrings(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("abc");
}


// Result 
//
// 2023-03-11: Runtime 34ms 26.49% Memory 17.1MB 24.91%, https://leetcode.com/problems/palindromic-substrings/submissions/913091287/


