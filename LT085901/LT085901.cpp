#include <lt_help/lt.h>

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len = s.length();
        if( len != goal.length())
            return false;
        
        static int buf[26];
        memset(buf, 0, sizeof(buf));
        
        int pos1=-1, pos2=-1;
        bool dup = false;
        for(int i = 0; i < len ; ++i)
        {   if(!dup && buf[s.at(i) - 'a']++ > 0)
                dup = true;           
            if( s.at(i) != goal.at(i))
            {   if( pos1== -1)
                    pos1 = i;
                else if( pos2 == -1)
                    pos2 = i;
                else
                    return false;
            }
        }
    
        return ( pos1==-1 && pos2==-1 && dup) 
            || ( pos1 != -1 && pos2 != -1 && s.at(pos1) == goal.at(pos2) && s.at(pos2) == goal.at(pos1) );
    }
};



void test(string s, string goal)
{
    cout << "input: s=" << s << ", goal=" << goal;
    bool r = Solution().buddyStrings(s, goal);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("ab", "ba");
}


// Result 
//
// 2022-12-02: Runtime 14ms 8.93% Memory 6.9MB 84.66%, https://leetcode.com/problems/buddy-strings/submissions/853281393/
// 2023-02-24: Runtime 3ms 84.49% Memory 7MB 67.62%, https://leetcode.com/problems/buddy-strings/submissions/904195924/


