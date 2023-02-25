#include <lt_help/lt.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if( size == 0 ) 
            return "";        
        if( size == 1 ) 
            return strs[0];

        string& first = strs[0];
        int pos = 0, len = first.length();
        for( int i = 1 ; i < size ; ++i)
            len = std::min(len, (int)strs[i].length());

        for(; pos < len; ++pos )
        {   char c = first[pos];
            for( int i = 1 ; i < size ; ++i)
            {  if( strs[i][pos] != c )
                    return first.substr(0, pos);
            }
        }

        return first.substr(0, len);
    }
};


void test(vector<string> strs)
{
    cout << "input: ";
    outputVector(strs);
    string r = Solution().longestCommonPrefix(strs);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({"flower", "flow", "flight"});
}

// Result 
//
// 2022-11-03: Runtime 10ms 20.28% Memory 9MB 95.8%, https://leetcode.com/problems/longest-common-prefix/submissions/836054535/
// 2023-02-15: Runtime 4ms 75.41% Memory 9.1MB 95.16%, https://leetcode.com/problems/longest-common-prefix/submissions/898539287/


