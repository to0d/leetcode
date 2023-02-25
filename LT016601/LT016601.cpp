#include <lt_help/lt.h>



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if ( numerator == 0 )
            return "0";
        long num = numerator, den = denominator;
        int negate = 0;
        if( num < 0)
        {   num = -num;
            negate++;
        }
        if( den < 0)
        {   den = -den;
            negate++;
        }
        
        static char buf [10000];
        int buf_len = 0;
        if( negate == 1 )
            buf[buf_len++] = '-';
        long dec = num/den;
        buf_len += sprintf(buf+buf_len, "%ld", dec);
        num %= den;
        
        if( num > 0 )
        {   unordered_map<long,int> _fra_map;
            buf[buf_len++] = '.';
            num *= 10;
            while( num > 0 )
            {   //cout << "num=" << num << ", buf_len=" << buf_len << ", buf=" << string(buf, buf_len) << endl;
                auto it = _fra_map.find(num);
                if( it != _fra_map.end() )
                {   int pos = it->second;
                    for(int i = buf_len; i > pos; --i)
                        buf[i] = buf[i-1];
                    buf[pos] = '(';
                    buf[buf_len+1] = ')';
                    buf_len += 2;
                    break;
                }
                _fra_map[num] = buf_len;
                buf[buf_len++] = '0' + (num/den);
                num = (num%den) * 10;
            }
        }

        return string(buf, buf_len);
    }
};


void test(int numerator, int denominator)
{
    cout << "input: num=" << numerator << ", den=" << denominator;   
    string r = Solution().fractionToDecimal(numerator, denominator);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(4, 333);
}

// Result 
//
// 2023-02-02: Runtime 0ms 100% Memory 6.4MB 39.81%, https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/890101059/




