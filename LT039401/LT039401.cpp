#include <lt_help/lt.h>

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return _decode(s, pos);
    }
    
    string _decode(string& s, int& pos) {   
        string rst;
        int len = s.length();
        while( pos < len )
        {   if( s.at(pos) == ']' )
            {   ++pos;
                break;
            }

            int num = 1;
            if( isdigit(s.at(pos)) )
                num = _nextNum(s, pos);

            string str;
            if( s.at(pos) == '[' )
                str = _decode(s, ++pos);
            else
                str = _nextStr(s, pos);
            
            for(int i = 0;i < num; ++i)
                rst += str;
        }
        return rst;
    }
    
    int _nextNum(string& s, int& pos) {
        int old = pos++, len = s.length();
        while( pos < len && isdigit(s.at(pos)) )
            ++pos;
        return std::stoi(s.substr(old, pos-old));
    }

    string _nextStr(string& s, int& pos) { 
        int old = pos++, len = s.length();
        while( pos < len && isalpha(s.at(pos)) )
            ++pos;
        return s.substr(old, pos-old);
    }
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
// 2023-03-12: Runtime 0ms 100% Memory 6.5MB 56.74%, https://leetcode.com/problems/decode-string/submissions/913314696/



