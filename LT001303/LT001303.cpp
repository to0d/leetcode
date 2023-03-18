#include <lt_help/lt.h>

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if( len == 0 )
            return 0;

        static int RMap[256] = {0};
        static bool RInit = false;
        if( !RInit )
        {   RMap['I'] = 1;
            RMap['V'] = 5;
            RMap['X'] = 10;
            RMap['L'] = 50;
            RMap['C'] = 100;
            RMap['D'] = 500;
            RMap['M'] = 1000;
            RInit = true;
        }

        int num = 0, pos = 0;
        while( pos < len )
        {   char c = s.at(pos);
            int pos2 = pos + 1;
            while( pos2 < len && s.at(pos2) == c )
                pos2++;
            
            if( pos2 == len )
            {   num += RMap[c]*(pos2-pos);
                break;
            }
            else
            {   char c2 = s.at(pos2);
                if( RMap[c2] < RMap[c] )
                {   num += RMap[c]*(pos2-pos);
                    pos = pos2;
                }
                else
                {   num += RMap[c2] - RMap[c]*(pos2-pos);
                    pos = pos2+1;
                }
            }
        }
        
        return num;
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



