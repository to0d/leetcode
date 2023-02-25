#include <lt_help/lt.h>



class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        static char buf[1000];
        vector<string> words;
        int buf_len = 0, len = text.length();
        for(int i = 0;i <= len ; ++i)
        {   char c = (i == len ? ' ' : text.at(i));
            if( c == ' ' )
            {   if( buf_len > 0 )
                    words.push_back(string(buf, buf_len));
                buf_len = 0;
            }
            else
                buf[buf_len++] = c;
        }
        //for( auto w : words) cout << " " << w; cout << endl;
        vector<string> rst;
        int size = words.size() - 2;
        for(int i = 0; i < size ; ++i)
        {   if( words[i] == first && words[i+1] == second )
                rst.push_back(words[i+2]);
        }
        
        return rst;
    }
};



void test(string text, string first, string second)
{
    cout << "input: text=" << text << ", first=" << first << ", second=" << second;
    vector<string> r = Solution().findOcurrences(text, first, second);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test("we will we will rock you", "we", "will");
}


// Result 
//
// 2022-12-09: Runtime 0ms 100% Memory 6.6MB 45.70%, https://leetcode.com/problems/occurrences-after-bigram/submissions/856920478/



