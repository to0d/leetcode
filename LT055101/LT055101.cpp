#include <lt_help/lt.h>

class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length(), ac = 0, lc = 0;
        for(int i =0; i < len; ++i)
        {   char c = s.at(i);
            switch(c)
            {   case 'A': 
                    if( ac++ > 0  ) 
                        return false; 
                    lc = 0; 
                    break;
                
                case 'L': 
                    if( lc++ >= 2 ) 
                        return false; 
                    break;
                
                default: 
                    lc = 0;
            }
        }
        
        return true;
    }
};


void test(string s)
{
    cout << "input: " << s << "; output: ";
    bool r = Solution().checkRecord(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("PPALLP");
}

// Result 
//
// 2022-11-19: Runtime 3ms 43.75% Memory 5.4MB 77.8%, https://leetcode.com/problems/student-attendance-record-i/submissions/846386353/
// 2023-02-24: Runtime 2ms 51.49% Memory 6.2MB 85.94%, https://leetcode.com/problems/student-attendance-record-i/submissions/904158155/
