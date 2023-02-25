#include <lt_help/lt.h>



class Solution {
public:
    string convert(string s, int n) {
        int len = s.size();
        if( len <= 1 || n <= 1)
            return s;

        int m = 2*n-2;
        int k = (len + m -1) / m; ; // round up
        
        static char buf[2000];
        memset(buf, 0, sizeof(buf));
        
        int pos = 0;

        for(int i = 0; i < n ;++i)
        {   for(int j = 0; j < k ;++j)
            {   pos += _move(s, j*m+i, len, buf+pos);
                if(i>0&& i<n-1) 
                {   pos += _move(s, j*m+m-i, len, buf+pos);
                }
            }            
        }

        return string(buf, len);
    }
    
    int _move(const string& s, int idx, int len, char* buf){   
        int pos = 0;
        if(idx >= len)
            return 0;
        //cout << "idx: " << idx << ", pos: " << pos << endl;
        buf[pos++] = s[idx];
        return pos;
    }
};


// PINYLHIPAIRAR
// PINALSIGYAHRPI

void test(string s, int n)
{
    cout << "input: s=" << s << ", n=" << n;
    string r = Solution().convert(s, n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("PAYPALISHIRING", 4);
}

// Result 
//
// 2023-02-08: Runtime 7ms 88.61% Memory 8.1MB 97.79%, https://leetcode.com/problems/zigzag-conversion/submissions/894133701/
