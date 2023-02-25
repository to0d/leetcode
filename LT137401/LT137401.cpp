#include <lt_help/lt.h>

class Solution {
public:
    string generateTheString(int n) {
        static char buf[500];
        int buf_len = 0;
        
        if( n >= 10 )
        {   int m = n - n%10;
            n = n%10;
            fill(buf+buf_len++, 'x', 1);
            fill(buf+buf_len  , 'y', m-1); 
            buf_len += m-1;
        }

        if( n%2 == 1)
        {   fill(buf+buf_len++, 'z', 1);
            --n;
        }

        if( n > 0)
        {   int m = n /2;
            if( m%2 == 0 )
                --m;
            fill(buf+buf_len, 'a', m); 
            buf_len += m;
            fill(buf+buf_len, 'b', (n-m)); 
            buf_len += n-m;
        }

        return string(buf, buf_len);
    }
    
    static void fill(char* buf, char c, int n) {   
        for(int i = 0; i < n; ++i)
            buf[i] = c;
    }
};



void test(int n)
{
    cout << "input: " << n;
    string r = Solution().generateTheString(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(4);
    test(14);
}


// Result 
//
// 2022-12-13: Runtime 4ms 36.74% Memory 6.4MB 30.48%, https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/submissions/858943309/
// 2023-02-25: Runtime 0ms 100% Memory 6.5MB 22.40%, https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/submissions/904212372/



