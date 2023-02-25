#include <lt_help/lt.h>

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        if( len == 0 )
            return 0;
        
        static int RomainMap[256] = {0};
        static int RMInit = 0;
        if( RMInit == 0)
        {
            RomainMap['I'] = 1;
            RomainMap['V'] = 5;
            RomainMap['X'] = 10;
            RomainMap['L'] = 50;
            RomainMap['C'] = 100;
            RomainMap['D'] = 500;
            RomainMap['M'] = 1000;
            RMInit = 1;
        }

        int num = 0, pos = 0;
        while( pos < len )
        {
            char c = s.at(pos);
            int pos2 = pos + 1;
            while( pos2 < len && s.at(pos2) == c )
                pos2++;
            
            if( pos2 == len )
            {   num += RomainMap[c]*(pos2-pos);
                break;
            }
            else
            {   char c2 = s.at(pos2);
                if( RomainMap[c2] < RomainMap[c] )
                {   num += RomainMap[c]*(pos2-pos);
                    pos = pos2;
                }
                else
                {   num += RomainMap[c2] - RomainMap[c]*(pos2-pos);
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



