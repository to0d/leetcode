#include <lt_help/lt.h>



class Solution {
public:
    string customSortString(string order, string s) {
        static int num[26];
        static char buf[200];
        int buf_len = 0, order_len = order.length(), s_len = s.length();
        for(int i = 0;i < 26; ++i)
            num[i] = -1;
        for(int i = 0;i < order_len; ++i)
            num[order.at(i)-'a'] = 0;
        for(int i = 0;i < s_len; ++i)
        {   int idx = s.at(i)-'a';
            if( num[idx] >=0 )
                num[idx]++;
        }
        for(int i = 0;i < order_len; ++i)
        {   int c = order.at(i);
            int count = num[c-'a'];
            for(int j = 0;j < count; ++j)
                buf[buf_len++] = c;
        }
        for(int i = 0;i < s_len; ++i)
        {   int c = s.at(i);
            int idx = c-'a';
            if( num[idx] < 0 )
                buf[buf_len++] = c;
        }
        return string(buf, buf_len);
    }
};

void test(string order, string s)
{
    cout << "input: order=" << order << ", s=" << s;
    string r = Solution().customSortString(order, s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("cba", "abcd");
}

// Result 
//
// 2023-01-29: Runtime 0ms 100% Memory 6.2MB 88.61%, https://leetcode.com/problems/custom-sort-string/submissions/887515126/
