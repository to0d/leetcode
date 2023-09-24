#include <lt_help/lt.h>

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if( len <= 1 )
            return s;
        vector<int> pi(len, 0);
        int max_idx = 0, max_len = 1;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < 2; ++j){
                for(int m = i, n = i+j; m >= 0 && n < len; --m, ++n){
                    if( s.at(m) != s.at(n) || pi[m] >= n )
                        break;
                    pi[m] = n;
                }
            }
            if( pi[i] == i && i < (len-1) && s.at(i) == s.at(i+1) ) // special case "bb"
                pi[i] = i+1;
        }
        
        for(int i = 0; i < len; ++i) {
            int len = pi[i] - i + 1;
            if(len > max_len)
            {   max_idx = i;
                max_len = len;
            }
        }
        
        return s.substr(max_idx, max_len); 
    }
};



void test(string s)
{
    cout << "input: " << s;    
    string r = Solution().longestPalindrome(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("babad");
}

// Result 
//
// 2023-02-08: Runtime 7ms 96.3% Memory 7MB 66.61%, https://leetcode.com/problems/longest-palindromic-substring/submissions/894121714/
// 2023-03-11: Runtime 11ms 91.51% Memory 7MB 75.25%, https://leetcode.com/problems/longest-palindromic-substring/submissions/913012417/
// 2023-07-20: Runtime 8 ms 97.01% Memory 6.8 MB 79.62%, https://leetcode.cn/submissions/detail/448583974/
// 2023-09-23: Runtime 44 ms 69.21% Memory 7.55 MB 76.41%, https://leetcode.cn/problems/longest-palindromic-substring/submissions/468957332/

