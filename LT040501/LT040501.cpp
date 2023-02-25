#include <lt_help/lt.h>

class Solution {
public:
    string toHex(int num) {
        static char buf[20];
        char* src = (char*)(&num);
        char* pos = src + sizeof(int) - 1;
        unsigned char c;
        int len = 0;

        while( pos >= src && (c=*pos) == 0 )
            --pos;
        
        if( pos >= src && c < 16 )
        {   buf[len++] = _to_hex(c);
            --pos;
        }
        
        for(; pos >= src; --pos)
        {   c = *pos;
            buf[len++] = _to_hex( (c & 0xf0) >> 4 );
            buf[len++] = _to_hex( c & 0xf );
        }
        
        if( len == 0 )
            buf[len++] = '0';

        return string(buf, len);
    }
    
    char _to_hex(unsigned char c) {   
        return (c < 10)?('0'+c): ('a'+(c-10));
    }
};



void test(int n)
{
    cout << "input: " << n;
    string r = Solution().toHex(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(26);
    test(-1);
}

// Result 
//
// 2022-11-21: Runtime 6ms 6.90% Memory 5.5MB 55.17%, https://leetcode.com/problems/convert-a-number-to-hexadecimal/submissions/846984974/
// 2023-02-22: Runtime 0ms 100% Memory 5.9MB 66.60%, https://leetcode.com/problems/convert-a-number-to-hexadecimal/submissions/902957238/


