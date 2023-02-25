#include <lt_help/lt.h>



class Solution {
public:
    int compress(vector<char>& chars) { 
        int len = 0, last_len = 0, size = chars.size();
        char last_c = 0; 
        static char buf[10];
        for( int i = 0; i <= size; ++i )
        {   char c = (i == size ? ' ' : chars[i]);
            if( c == last_c )
                last_len ++;
            else
            {   //cout << "last_c=" << last_c << ", last_len=" << last_len << ", len=" << len << endl;
                if( last_len > 0 )
                {   chars[len++] = last_c;
                    if( last_len > 1 )
                    {   int buf_len = sprintf(buf, "%d", last_len);
                        for(int j = 0;j < buf_len; ++j)
                            chars[len++] = buf[j];
                    }
                }
                last_len = 1;
                last_c   = c;
            }
        }
        return len;
    }
};


void test(vector<char> chars)
{
    cout << "input: "; 
    outputVector(chars); 
    int r = Solution().compress(chars);
    chars.resize(r);
    cout << "; output: ";
    outputVector(chars);
    cout << ";" << endl;
}

int main(void)
{
    test({'a','a','b','b','c','c','c'});
}

// Result 
//
// 2023-01-28: Runtime 5ms 70.37% Memory 9.1MB 42.26%, https://leetcode.com/problems/string-compression/submissions/886898280/


