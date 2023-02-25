#include <lt_help/lt.h>

class Solution {
public:
    string thousandSeparator(int n) {
        static char buf[64];
        int pos = sizeof(buf)-1;
        for(int i = 0; n > 0 ; n /= 10, ++i)
        {   if( i > 0 && i%3 == 0)
                buf[pos--] = '.';
            buf[pos--] = '0' + (n%10);
        }

        int len = sizeof(buf)-pos-1;
        return len == 0 ? "0" : string(buf+pos+1, len);
    }
};



void test(int n)
{
    cout << "input: " << n;
    string r = Solution().thousandSeparator(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(1234);
}


// Result 
//
// 2022-12-15: Runtime 4ms 6.64% Memory 6MB 9.96%, https://leetcode.com/problems/thousand-separator/submissions/859954182/
// 2023-02-25: Runtime 0ms 100% Memory 5.8MB 92.83%, https://leetcode.com/problems/thousand-separator/submissions/904217381/



