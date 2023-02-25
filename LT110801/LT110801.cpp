#include <lt_help/lt.h>



class Solution {
public:
    string defangIPaddr(string address) {
        static char buf[128];
        int buf_len = 0, len = address.length();
        for(int i = 0; i < len; ++i)
        {   char c = address.at(i);
            if( c != '.' )
                buf[buf_len++] = c;
            else
            {   buf[buf_len++] = '[';
                buf[buf_len++] = c;
                buf[buf_len++] = ']';
            }
        }
        return string(buf, buf_len);
    }
};



void test(string address)
{
    cout << "input: " << address;
    string r = Solution().defangIPaddr(address);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("1.1.1.1");
}


// Result 
//
// 2022-12-09: Runtime 0ms 100% Memory 6MB 73.71%, https://leetcode.com/problems/defanging-an-ip-address/submissions/856934589/



