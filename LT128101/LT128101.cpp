#include <lt_help/lt.h>



class Solution {
public:
    int subtractProductAndSum(int n) {
        static int buf[64];
        int len = digitOf(n, buf);
        int product = 1, sum = 0;
        for(int i = 0;i < len; ++i)
        {   product *= buf[i];
            sum     += buf[i];;
        }
        return product - sum;
    }
    int digitOf(int n, int* buf)
    {   int d = 0;
        for(; n > 0; n/=10)
            buf[d++] = n%10;
        return d;
    }
};

void test(int num)
{
    cout << "input: " << num;
    int r = Solution().subtractProductAndSum(num);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(234);
}


// Result 
//
// 2022-12-12: Runtime 0ms 100% Memory 5.9MB 92.87%, https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/submissions/858676821/



