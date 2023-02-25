#include <lt_help/lt.h>




class Solution {
public:
    string decodeString(string s) {
        m_p = s.c_str();
        return _decode(0);
    }
    
    string _decode(int level)
    {   string rst;
        char c;

        while( (c = *m_p) != 0 )
        {   if( c == ']' )
            {   ++m_p;
                break;
            }
            
            int num = 1;
            if( _isNum(c) )
            {   num = _nextNum();
            }            
            
            string str;
            if( *m_p == '[' )
            {   ++m_p;
                str = _decode(level+1);
            }
            else
                str = _nextStr();
            
            for(int i = 0;i < num; ++i)
                rst += str;
            
            //cout << "level=" << level << ", num=" << num << ", str=" << str << ", rst=" << rst << endl;
        }

        return rst;
    }
    
    int _nextNum()
    {   const char* p2 = m_p;
        char c;
        while( (c = *p2) != 0 && _isNum(c) )
            ++p2;
        if( m_p == p2 )
            return 0;
        int val = std::stoi(string(m_p, p2-m_p));
        m_p = p2;
        return val;
    }
    
    string _nextStr()
    {   const char* p2 = m_p;
        char c;
        while( (c = *p2) != 0 && _isChar(c) )
            ++p2;
        if( m_p == p2 )
            return "";
        string str = string(m_p, p2-m_p);
        m_p = p2;
        return str;
    }
    
    bool _isNum(char c)
    {   return c >= '0' && c <= '9';
    }
    
    bool _isChar(char c)
    {   return c >= 'a' && c <= 'z';
    }
    
    const char* m_p;
};


void test(string s)
{
    cout << "input: " << s;
    string r = Solution().decodeString(s);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("3[a]2[bc]");
}


// Result 
//
// 2023-01-05: Runtime 2ms 46.46% Memory 6.6MB 55.37%, https://leetcode.com/problems/decode-string/submissions/872027039/



