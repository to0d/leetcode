#include <lt_help/lt.h>



class Solution {
public:
    vector<int> lexicalOrder(int n) {
        static int buf[6];
        int len = 0, last = 0;
        vector<int> rst;
        for(int i = 0; i < n; ++i)
        {   if( i == 0 )
            {   rst.push_back(1);
                buf[0] = 1;
                len    = 1;
                last   = 1;
            }
            else
            {   buf[len] = 0;
                int val = _numOf(buf, len+1);
                if( val <= n )
                {   rst.push_back(val);
                    len++;
                    last = val;
                }
                else
                {   if( last == n )
                        len--;
                    int j = len-1;
                    bool found = false;
                    while( !found )
                    {   if( buf[j] < 9 )
                        {   buf[j]++;
                            found = true;
                        }
                        else
                        {   --len;
                            --j;
                        }
                    }
                    val = _numOf(buf, len);
                    rst.push_back(val);
                    last = val;
                }
            }
        }
        
        return rst;
    }
    
    int _numOf(int* buf, int len)
    {   int val = 0, d = 1;
        for(int i = len-1; i >=0; --i, d*= 10)
            val += d*buf[i];
        return val;
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<int> r = Solution().lexicalOrder(n);
    cout << "; output: ";
    outputVector(r); 
    cout << ";" << endl;
}


int main(void)
{
    test(13);
}

// Result 
//
// 2023-02-05: Runtime 13ms 60.32% Memory 11.1MB 68.80%, https://leetcode.com/problems/lexicographical-numbers/submissions/892040147/



