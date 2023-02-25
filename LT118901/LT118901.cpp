#include <lt_help/lt.h>

class Solution {
public:
    int maxNumberOfBalloons(string text) {        
        static int buf2[26];
        static bool init = false;
        if( !init )
        {   string b = "balloon";
            _count(b, buf2);
            init = true;
        }

        int buf1[26];        
        _count(text, buf1);
        
        int mm = text.length();
        for(int i = 0; mm > 0 && i < 26; ++i)
            if(buf2[i] > 0)
                mm = std::min(mm, buf1[i]/buf2[i]);
        
        return mm;
    }

    static int _count(string s, int* buf) {   
        int len = s.length(), count = 0;
        memset(buf, 0, sizeof(int)*26);
        for(int i = 0; i < len; ++i)
            if(buf[s.at(i)-'a']++ == 0)
                ++count;
        return count;
    }
};



void test(string text)
{
    cout << "input: " << text;
    int r = Solution().maxNumberOfBalloons(text);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("loonbalxballpoon");
}


// Result 
//
// 2022-12-12: Runtime 6ms 37.66% Memory 6.7MB 58.47%, https://leetcode.com/problems/maximum-number-of-balloons/submissions/858393143/
// 2023-02-24: Runtime 2ms 81.98% Memory 6.6MB 92.32%, https://leetcode.com/problems/maximum-number-of-balloons/submissions/904203968/




