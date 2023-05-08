#include <lt_help/lt.h>

// a     b       c     c*m
// 1     9       9     9*1
// 10    99      90    90*2
// 100   999     900   900*3
// 1000  9999    9000  9000*4

class Solution {
public:
    int findNthDigit(int n) {
        long x = n;
        long a = 1, b = 9, c = 9, m = 1, low=0, high=c*m;
        while ( x > high )
        {   x -= high;
            a  *= 10;
            b   = b*10+9;
            c  *= 10;          
            low = high;
            m++;   
            high=c*m; 
        }
        long y = (x-1) / m + a;
        long z = m - (x-1) % m - 1;

        for(; z > 0; --z)
            y /= 10;
        return (int) y%10;
    }
};

void test(int n)
{
    cout << "input: " << n;
    int r = Solution().findNthDigit(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3);
    test(11);
}

// Result 
//
// 2023-05-08: Runtime 0ms 100% Memory 6MB 49.43%, 

