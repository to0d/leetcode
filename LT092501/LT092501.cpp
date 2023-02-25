#include <lt_help/lt.h>



class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1=name.length(), len2=typed.length(), pos1 = 0, pos2 = 0;
        while(pos1 < len1 && pos2 < len2)
        {   char c = name.at(pos1);
            if( c != typed.at(pos2) )
                break;
            ++pos1;
            ++pos2;
            //cout << "loop1: pos1=" << pos1 << ", pos2=" << pos2 << endl;
            if( pos1 == len1 || (pos1 < len1 && c != name.at(pos1)))
            {    while(pos2 < len2 && typed.at(pos2) == c)
                    ++pos2;
                 //cout << "loop2: pos2=" << pos1 << ", pos2=" << pos2 << endl;
            }
                
        }
        //cout << "pos1=" << pos1 << ", pos2=" << pos2 << endl;
        return pos1 == len1 && pos2 == len2;
    }
};


void test(string name, string typed)
{
    cout << "input: name=" << name << ", typed=" << typed;
    bool r = Solution().isLongPressedName(name, typed);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("alex", "aaleex");
}


// Result 
//
// 2022-12-02: Runtime 0ms 100% Memory 6.4MB 70.56%, https://leetcode.com/problems/long-pressed-name/submissions/853290755/



