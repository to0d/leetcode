#include <lt_help/lt.h>

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if( str1.length() < str2.length() )
            return _gcdOfStrings(str2, str2.length(), str1, str1.length());
        else
            return _gcdOfStrings(str1, str1.length(), str2, str2.length());
    }

    string _gcdOfStrings(string str1, int len1, string str2, int len2) {
        int common_len = 0;
        
        for( ; common_len < len2; ++common_len)
            if( str1.at(common_len) != str2.at(common_len) )
                break;
        
        for(; common_len > 0;  --common_len)
            if( _isSub(str2, len2, common_len) && _isSub(str1, len1, common_len) )
                break;
        
        return str1.substr(0, common_len);
    }

    bool _isSub(string str, int len, int sub){   
        if( len == sub )
            return true;
        if( len % sub != 0 )
            return false;
        int n = len / sub;
        for( int i = 1;i < n ; ++i)
            for( int j = 0;j < sub; ++j)
                if( str.at(j) !=  str.at(i*sub + j))
                    return false;
        return true;
    }
};



void test(string str1, string str2)
{
    cout << "input: str1=" << str1 << ", str2=" << str2;
    string r = Solution().gcdOfStrings(str1, str2);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("ABCABC", "ABC");
}


// Result 
//
// 2022-12-08: Runtime 10ms 12.70% Memory 16.8MB 10.40%, https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/856658596/
// 2023-02-18: Runtime 4ms 44.19% Memory 16.9MB 10.37%, https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/900116898/



