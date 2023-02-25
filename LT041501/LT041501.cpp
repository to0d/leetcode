#include <lt_help/lt.h>

class Solution {
public:
    string addStrings(string a, string b) {
        int a_size = a.size(), b_size = b.size();
        if( a_size == 0 || b_size == 0 )
            return a + b;

        static char buf[20000];
        int lc = std::max(a_size,b_size) + 1;
        int pc(lc -1), v(0);

        for(int pa=a_size-1, pb=b_size-1; pa >= 0 || pb >=0; --pa, --pb, --pc, v /= 10)
        {   if( pa >= 0 )
                v += (int)(a.at(pa) - '0');
            if( pb >= 0 )
                v += (int)(b.at(pb) - '0');
            buf[pc] = v%10 + '0';
        }

        if( v > 0 )
           buf[0] = v + '0';
        else
           pc++;

        return string(buf + pc, lc - pc);
    }
};



void test(string a, string b)
{
    cout << "input: a=" << a << ", b=" << b;
    string r = Solution().addStrings(a, b);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("456", "77");
}

// Result 
//
// 2022-11-25: Runtime 8ms 47.59% Memory 6.9MB 42.8%, https://leetcode.com/problems/add-strings/submissions/849496541/
// 2023-02-22: Runtime 0ms 100% Memory 6.7MB 70.55%, https://leetcode.com/problems/add-strings/submissions/902961357/

