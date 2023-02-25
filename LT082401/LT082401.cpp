#include <lt_help/lt.h>

class Solution {
public:
    string toGoatLatin(string sentence) {
        static char buf[4096];
        int len = sentence.length(), count = 0, last = -1, num = 0;
        for(int i = 0; i <= len ; ++i)
        {   char c = (i == len) ? ' ' : sentence.at(i);
            if(last == -1)
            {   if(c == ' ')
                    buf[count++] = ' ';
                else
                    last = i;
            }
            else if(c == ' ')
            {   char cc = sentence.at(last); 
                if(!isVowel(cc))
                    ++last;
                else
                    cc = 0;
                
                for(int j = last; j < i; ++j)
                    buf[count++] = sentence.at(j);
                
                if( cc != 0 )
                    buf[count++] = cc;

                buf[count++] = 'm';
                buf[count++] = 'a';
                
                for(int j = 0; j <= num; ++j)
                    buf[count++] = 'a';
                
                buf[count++] = ' ';
                num++;
                last = -1;
            }
        }

        if( num > 0 )
            --count;

        return string(buf, count);
    }
    
    static bool isVowel(char c){   
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};



void test(string sentence)
{
    cout << "input: " << sentence;
    string r = Solution().toGoatLatin(sentence);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("I speak Goat Latin");
}


// Result 
//
// 2022-12-04: Runtime 4ms 35.93% Memory 6.4MB 78.14%, https://leetcode.com/problems/goat-latin/submissions/854162984/
// 2023-02-24: Runtime 0ms 100% Memory 6.4MB 91.57%, https://leetcode.com/problems/goat-latin/submissions/904193723/


