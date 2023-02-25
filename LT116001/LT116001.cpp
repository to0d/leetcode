#include <lt_help/lt.h>



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        static char buf1[26], buf2[26];
        int rst = 0;
        cal(buf1, chars);
        for(string& word: words)
        {   cal(buf2, word);
            bool found = false;
            for(int i=0; !found && i < 26; ++i)
            {   if( buf2[i] > buf1[i] )
                    found = true;
            }
            if( !found )
                rst += word.length();
        }
        return rst;
    }
    void cal(char* buf, string& s)
    {   int size = s.length();
        memset(buf, 0, 26);
        for(int i = 0; i < size; ++i)
            buf[s.at(i)-'a']++;
    }
};


void test(vector<string> words, string chars)
{
    cout << "input: chars=" << chars << ", words=";
    outputVector(words);
    int r = Solution().countCharacters(words, chars);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({"cat","bt","hat","tree"}, "atach");
}


// Result 
//
// 2022-12-21: Runtime 40ms 98.62% Memory 15.4MB 92.48%, https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/862988260/



