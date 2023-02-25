#include <lt_help/lt.h>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        char stHeap [256] = {0}, tsHeap [256] = {0};
        for(int i = 0; i < len ; ++i)
        {   char sc = s[i], tc = t[i];
            char msc = stHeap[(int)sc], mtc = tsHeap[(int)tc];
            if( msc == 0 )
            {   if( mtc == 0 )
                {   stHeap[(int)sc] = tc;
                    tsHeap[(int)tc] = sc;
                }
                else
                    return false;
            }
            else if(msc != tc || mtc != sc)
                return false;
        }

        return true;
    }
};


   
void test(string s, string t)
{
    cout << "input: s=" << s << ", t=" << t;
    bool r = Solution().isIsomorphic(s, t);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("egg", "add");
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 5.9MB 39.85%, https://leetcode.com/problems/isomorphic-strings/submissions/847514582/
// 2023-02-22: Runtime 3ms 95.90% Memory 6.7MB 98.83%, https://leetcode.com/problems/isomorphic-strings/submissions/902720713/

