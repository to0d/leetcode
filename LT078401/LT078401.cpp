#include <lt_help/lt.h>



class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        static char buf[20];
        static bool lower[20];
        vector<string> rst;
        int pos = 0, len = s.length();        
        bool push = true;
        while( pos >= 0 )
        {   //cout << "push=" << push << ", pos=" << pos << ", buf=" << string(buf, pos) << endl;
            if( push )
            {   if( pos == len)
                {   rst.push_back(string(buf, len));
                    push = false;
                    --pos;
                }
                else
                {   buf[pos] = tolower(s.at(pos));
                    lower[pos] = true;
                    ++pos;
                }                
            }
            else
            {   if( lower[pos] == true)
                {   char c2 = toupper(s.at(pos));
                    if( c2 != buf[pos])
                    {   buf[pos] = c2;
                        lower[pos] = false;
                        push = true; 
                        ++pos;
                        continue;
                    }
                }
                --pos;
            }
        }
        return rst;
    }
};


void test(string s)
{
    cout << "input: " << s;
    vector<string> r = Solution().letterCasePermutation(s);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test("a1b2");
}

// Result 
//
// 2023-01-19: Runtime 0ms 100% Memory 9.3MB 98.79%, https://leetcode.com/problems/letter-case-permutation/submissions/880990598/


