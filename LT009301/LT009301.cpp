#include <lt_help/lt.h>



class Solution {
public:
    vector<string> restoreIpAddresses(string s) {        
        vector<string> rst;
        static char buf[24];
        _restoreIpAddresses(buf, 0, s.c_str(), s.length(), 0, rst);
		return rst;
    }
    
    void _restoreIpAddresses(char* buf, int buf_len, const char* str, int str_len, int deep, vector<string>& rst)
    {   if( deep == 3 )
        {   if(_isValidNum(str, str_len))
            {   memcpy(buf+buf_len, str, str_len);
                rst.push_back(string(buf, buf_len+str_len));
            }
            return;
        }
        for(int len=1; len <= 3 && len <= str_len; ++len)
        {   if(!_isValidNum(str, len))
                continue;
            memcpy(buf+buf_len, str, len);
            buf[buf_len+len] = '.';
            _restoreIpAddresses(buf, buf_len+len+1, str+len, str_len-len, deep+1, rst);
        }
    }
    
    bool _isValidNum(const char* p, int len)
    {   if( len <= 0 || len > 3 )
            return false;
        if( p[0] == '0' && len > 1 )
            return false;
        if( std::stoi(string(p, len)) > 255 )
			return false;
		return true;
    }
};



void test(string s)
{
    cout << "input: " << s;
    vector<string> r = Solution().restoreIpAddresses(s);
    cout << "; output: ";
	outputVector(r);
	cout << ";" << endl;
}

int main(void)
{   test("25525511135");
}


// Result 
//
// 2022-12-28: Runtime 2ms 64.95% Memory 6.5MB 85.83%, https://leetcode.com/problems/restore-ip-addresses/submissions/866994442/



