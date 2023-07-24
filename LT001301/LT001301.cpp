#include <lt_help/lt.h>

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if( len == 0 )
            return 0;
        
        static int  RomanNum[256] = {0};
        static bool RInit = false;
        if( !RInit )
        {   RomanNum['I'] = 1;
            RomanNum['V'] = 5;
            RomanNum['X'] = 10;
            RomanNum['L'] = 50;
            RomanNum['C'] = 100;
            RomanNum['D'] = 500;
            RomanNum['M'] = 1000;
            RInit = true;
        }

        int val = 0, pos = 0;
        while(pos < len)
        {   int v1 = RomanNum[s[pos]], v2 = 0, n = 1;
            for(int i = pos+1; i < len; ++i, ++n)
                if( (v2 = RomanNum[s[i]]) != v1 )
                    break;
            if( v2 <= v1 )
            {   val += v1*n;
                pos += n;
            }
            else
            {   val += v2 - v1*n;
                pos += n +1;
            }
        }
        return val;
    }
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().romanToInt(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("MCMXCIV");
}


// Result 
//
// 2023-02-15: Runtime 7ms 86.76% Memory 6MB 90.65%, https://leetcode.com/problems/roman-to-integer/submissions/898531906/
// 2023-03-15: Runtime 11ms 73.58% Memory 6MB 75.87%, https://leetcode.com/problems/roman-to-integer/submissions/915710368/
// 2023-07-24: Runtime 8ms 82.08% Memory 5.64MB 95.02%, https://leetcode.cn/problems/roman-to-integer/submissions/449693492



