#include <lt_help/lt.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int a_size = a.size(), b_size = b.size();
        if( a_size == 0 || b_size == 0 )
            return a + b;

        int lc  = std::max(a_size, b_size) + 1;
        int pa(a.size()-1), pb(b.size()-1), pc(lc -1), v(0);
        static char buf[10002];
        
        for(; pa >= 0 || pb >=0; --pa, --pb, --pc, v/=2 )
        {   v += ( pa >= 0 && a.at(pa) == '1' ? 1 : 0);
            v += ( pb >= 0 && b.at(pb) == '1' ? 1 : 0);  
            buf[pc] = v % 2 + '0';
        }

        if( v > 0 )
           buf[0] = '1';
        else
           pc++;

        string r(buf + pc, lc - pc); 
        return r;
    }
};



void test(string a, string b)
{
    cout << "input: a=" << a << ", b=" << b << "; output: ";
    string r = Solution().addBinary(a, b);
    cout << r << ";" << endl;
}

int main(void)
{
    test("1010", "1011");
}

// Result 
//
// 2022-11-19: Runtime 3ms 68.26% Memory 6.5MB 40.20%, https://leetcode.com/problems/add-binary/submissions/845898717/
// 2023-02-18: Runtime 3ms 61.86% Memory 6.3MB 61.91%, https://leetcode.com/problems/add-binary/submissions/900084897/


