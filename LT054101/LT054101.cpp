#include <lt_help/lt.h>

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        if( len == 0 )
            return s;
        static char buf[10000];        
        memcpy(buf, s.c_str(), len);
        _reverseStr(buf, len, k);
        return string(buf, len);
    }
    
    void _reverseStr(char* s, int len, int k) {
        if( len == 0 )
            return;
        
        if( len < k )
        {   _reverseStr(s, len, len);
            return;
        }
        
        if( len <= 2*k && len > k ) 
        {   _reverseStr(s, k, k);
            return;
        }
        
        if( len > 2*k )
        {   _reverseStr(s, k, k);
            _reverseStr(s+2*k, len-2*k, k);
            return;
        }

        for(int l = 0, h=k-1; l < h; ++l, --h )
        {   char t = s[l];
            s[l] = s[h];
            s[h] = t;
        }
    }
};



void test(string s, int k)
{
    cout << "input: s=" << s << ", k=" << k;
    string r = Solution().reverseStr(s, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("abcdefg", 2);
}

// Result 
//
// 2022-11-19: Runtime 5ms 52.31% Memory 6.3MB 12.31%, https://leetcode.com/problems/reverse-string-ii/submissions/846387720/
// 2023-02-25: Runtime 4ms 70.69% Memory 7.4MB 24.49%, https://leetcode.com/problems/reverse-string-ii/submissions/904440363/



