#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b)
{   return a[0] < b[0];
}

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length(), stack_len = 0;
        static int stack[30000];
        vector<vector<int>> len_vec;
        for(int i = 0; i < size; ++i)
        {   switch(s.at(i))
            {
            case '(': 
                stack[stack_len++] = i;
                break;
            case ')':
                if( stack_len > 0 )
                    len_vec.push_back({stack[--stack_len], i});
                break;
            }
        }
        std::sort(len_vec.begin(), len_vec.end(), less_interval);
        // for(auto v : len_vec) cout << "[" << v[0] << ", " << v[1] << "] "; cout << endl;

        int max_len = 0, last_begin = -1, last_end = -1;
        for(auto v : len_vec)
        {   if( last_begin == -1 || v[0] > (last_end+1))
            {   last_begin = v[0];
                last_end   = v[1];
            }
            else if(v[1] > last_end)
                last_end   = v[1];
            max_len = std::max(max_len, (last_end-last_begin+1));
        }
        
        return max_len;
    }
};


void test(string s)
{
    cout << "input: " << s;
    int r = Solution().longestValidParentheses(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("()(()");
}


// Result 
//
// 2022-12-06: Runtime 18ms 10.75% Memory 11MB 5.4%, https://leetcode.com/problems/longest-valid-parentheses/submissions/855322425/
// 2023-02-17: Runtime 27ms 8.52% Memory 11MB 5.28%, https://leetcode.com/problems/longest-valid-parentheses/submissions/899501236/


