#include <lt_help/lt.h>


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const char* pre = searchWord.c_str();
        static char buf[100];
        int idx = 0, buf_len = 0, len = sentence.length(), pre_len = searchWord.length();
        for(int i = 0; i <= len; ++i)
        {   char c = (i == len ? ' ' : sentence.at(i));
            if( c == ' ' )
            {   if( buf_len >= pre_len && isEqual(buf, pre, pre_len))
                    return idx;
                buf_len = 0;
            }
            else
            {   if( buf_len == 0 )
                   idx++;
                buf[buf_len++] = c;
            }
        }
        return -1;
    }
    bool isEqual(char* t, const char* s, int len)
    {   for(int i = 0;i < len; ++i)
            if(t[i] != s[i])
                return false;
        return true;
    }
};


void test(string sentence, string searchWord)
{
    cout << "input: sentence=" << sentence << ", searchWord=" << searchWord;
    int r = Solution().isPrefixOfWord(sentence, searchWord);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("i kk", "k");
}


// Result 
//
// 2022-12-15: Runtime 0ms 100% Memory 6.2MB 13.66%, https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/submissions/860222260/



