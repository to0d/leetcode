#include <lt_help/lt.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size(), len = INT_MAX;
        if( size == 0 ) return "";        
        if( size == 1 ) return strs[0];

        for(auto& s : strs)
            len = std::min(len, (int)s.length());

        for(int i = 0; i < len; ++i)
        {   char c = strs[0][i];
            for(int j = 1 ; j < size ; ++j)
                if( strs[j][i] != c )
                    return strs[0].substr(0, i);
        }

        return strs[0].substr(0, len);
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
// 2023-03-15: Runtime 0ms 100% Memory 9.1MB 83.3%, https://leetcode.com/problems/longest-common-prefix/submissions/915715812/


