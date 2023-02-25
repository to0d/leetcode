#include <lt_help/lt.h>

class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        if( len != goal.length())
            return false;

        int buf1[26], buf2[26];
        memset(buf1, 0, sizeof(buf1));
        memset(buf2, 0, sizeof(buf2));
        _statistics(s, buf1);
        _statistics(goal, buf2);

        for(int i = 0; i < 26; ++i)
            if( buf1[i] != buf2[i] )
                return false;

        for(int i = 0; i < len; ++i)
            if(_rotateString(s, goal, i))
                return true;

        return false;
    }
    
    void _statistics(string& s, int* buf){   
        int len = s.length();
        for(int i = 0; i < len; ++i)
            buf[s.at(i)-'a']++;
    }
    
    bool _rotateString(string& s, string& goal, int pos){   
        int len = s.length();
        for(int i = 0; i < len; ++i)
            if(s.at((i+pos)%len) != goal.at(i))
                return false;
        return true;
    }
};



void test(string s, string goal)
{
    cout << "input: s=" << s << ", goal=" << goal;
    bool r = Solution().rotateString(s, goal);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("abcde", "cdeab");
}


// Result 
//
// 2022-12-02: Runtime 3ms 48.20% Memory 6.5MB 19.37%, https://leetcode.com/problems/rotate-string/submissions/853274167/
// 2023-02-24: Runtime 0ms 100% Memory 6MB 88.37%, https://leetcode.com/problems/rotate-string/submissions/904192902/



