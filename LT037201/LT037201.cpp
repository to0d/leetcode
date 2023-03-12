#include <lt_help/lt.h>


class Solution {
#define MOD_VAL 1337
public:
    int superPow(int a, vector<int>& b) {
        return _superPow(a, b, b.size(), b.size());
    }
    
    int _superPow(int a, vector<int>& b, int size, int len) {
        if( a == 0 ) return 0;
        if( a == 1 ) return 1;
        if( a >= MOD_VAL )
           return _superPow( a % MOD_VAL, b, size, len ); 
        
        int xx = b[size-1];
        if( len == 1 && xx == 1 )
            return a;

        bool odd = false;
        if( xx % 2 == 1)
        {   b[size-1]--;
            odd = true;
        }

        int last = 0;
        bool isZero = true;
        for(int i = size-len; i < size; ++i)
        {   int v = last + b[i];
            b[i] = v / 2;
            last = (v % 2) * 10;
            if( b[i] == 0)
            {   if( isZero )
                    --len; 
            }
            else
                isZero = false;
        }

        int val = _superPow(a*a, b, size, len);
        if( odd )
            val = (val*a) % MOD_VAL;

        return val;
    }
};



void test(int a, vector<int> b)
{
    cout << "input: a=" << a << ", b=";
    outputVector(b);
    int r = Solution().superPow(a, b);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(1, {4,3,3,8,5,2});
}

// Result 
//
// 2023-01-05: Runtime 1585ms 5.4% Memory 12MB 7.97%, https://leetcode.com/problems/super-pow/submissions/871635775/
// 2023-03-11: Runtime 874ms 6.98% Memory 12.1MB 5.68%, https://leetcode.com/problems/super-pow/submissions/912960013/

