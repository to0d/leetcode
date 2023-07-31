#include <lt_help/lt.h>

class Solution {
public:
    int nextGreaterElement(int n) {
        static int buf[11];
        int len = 0;
        for(; n > 0; n /= 10 )
            buf[len++] = n%10;
        int last_max = buf[0];
        for(int i = 1; i < len; ++i)
        {   if( buf[i] >= last_max )
                last_max = buf[i];
            else
            {   int* min_max = &(buf[i-1]);
                for(int j = i-2; j >= 0; --j)
                    if( buf[j] <= buf[i])
                        break;
                    else
                        min_max = &(buf[j]);
                int t  = buf[i];
                buf[i] = *min_max;
                *min_max = t;
                std::sort(begin(buf), begin(buf)+i, greater<int>());
                long val = 0;
                for(int k = len-1; k >= 0; --k)
                    val = val*10 + buf[k];
                return val > INT_MAX ? -1 : (int)val;
            }
        }
        return -1;
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().nextGreaterElement(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(45312);
}

// Result 
//
// 2023-07-31: Runtime 0ms 100.00% Memory 5.69MB 55.00%, https://leetcode.cn/problems/next-greater-element-iii/submissions/451882820/

