#include <lt_help/lt.h>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rst, tmp;
        int wordSumLen = 0, word_size = words.size();
        for(int i = 0; i <= word_size; ++i)
        {   if( (i == word_size) || (wordSumLen + words[i].length() + tmp.size()) > maxWidth )
            {   rst.push_back(makeLine(tmp, wordSumLen, maxWidth, i == word_size));
                if(i == word_size)
                    break;
                tmp.clear();
                wordSumLen = 0;
            }
            tmp.push_back(words[i]);
            wordSumLen += words[i].length();
        }
        return rst;
    }

    static string makeLine(vector<string>& vec, int wordSumLen, int maxWidth, bool last){
        static char buf[100];
        int buf_len = 0;

        {   string& word = vec[0];
            int len = word.length();
            memcpy(buf, word.c_str(), len);
            buf_len = len;            
        }

        if(vec.size() == 1 )
        {   memset(buf+buf_len, ' ', maxWidth - buf_len);
            return string(buf, maxWidth);
        }

        if(last)
        {   for(int i = 1; i < vec.size(); ++i)
            {   memset(buf+buf_len, ' ', 1);
                buf_len ++;
                string& word = vec[i];
                int len = word.length();  
                memcpy(buf + buf_len, word.c_str(), len); 
                buf_len += len;
            }
            if( buf_len < maxWidth )
                memset(buf+buf_len, ' ', maxWidth - buf_len);
            return string(buf, maxWidth);
        }
        
        int spaceLen = maxWidth - wordSumLen;
        int spaceGap = spaceLen/(vec.size()-1);
        int spaceMor = spaceLen - spaceGap*(vec.size()-1);
        for(int i = 1; i < vec.size(); ++i)
        {   memset(buf+buf_len, ' ', spaceGap);
            buf_len += spaceGap;
            if( i <= spaceMor )
            {   memset(buf+buf_len, ' ', 1);
                buf_len ++;
            }
            string& word = vec[i];
            int len = word.length();  
            memcpy(buf + buf_len, word.c_str(), len);
            buf_len += len;
        }

        return string(buf, maxWidth);
    }
};



void test(vector<string> words, int maxWidth)
{
    cout << "input: width=" << maxWidth << ", words=";
    outputVector(words);
    vector<string> r = Solution().fullJustify(words, maxWidth);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({"This", "is", "an", "example", "of", "text"}, 8);
}


// Result 
//
// 2022-12-27: Runtime 5ms 26.74% Memory 7.5MB 19.19%, https://leetcode.com/problems/text-justification/submissions/866355719/
// 2023-02-18: Runtime 5ms 27.93% Memory 7.5MB 18.4%, https://leetcode.com/problems/text-justification/submissions/900087692/


