#include <lt_help/lt.h>

class Solution {
public:
    int getSum(int a, int b) {
        int s = a ^ b;
        int carry = a & b;
        if( carry == 0 )
            return s;
        else
            return getSum(s, carry << 1); 
    }
};



void test(int a, int b)
{
    cout << "input: a=" << a << ", b=" << b;
    int r = Solution().getSum(a, b);
    cout << "; output: " << r << endl; 
}


int main(void)
{ 
    test(1, 2);
    test(2, 3);
}

// Result 
//
// 2022/11/21
//      runtime error
//      -1
//      1