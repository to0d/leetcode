#include <lt_help/lt.h>



class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> tmp, rst;
        fill(tmp, s1);
        fill(tmp, s2);
        std::sort(tmp.begin(), tmp.end());
        string last = "";
        bool remove_last = false;
        for(string& s : tmp )
        {   if( s == last )
            {   if(!remove_last)
                {   rst.erase(rst.begin()+rst.size()-1);
                    remove_last = true;
                }
                continue;
            }
            rst.push_back(s);
            last = s;
            remove_last = false;
        }

        return rst;
    }
    
    void fill(vector<string>& v, string s)
    {   static char buf[200];
        int buf_len = 0, len = s.length();
        for(int i=0; i <= len; ++i)
        {   char c = (i == len? ' ' : s.at(i));
            if( c == ' ' )
            {   if( buf_len > 0 )
                    v.push_back(string(buf, buf_len));
                buf_len = 0;
            }
            else
                buf[buf_len++] = c;           
        }
    }
};


void test(string s1, string s2)
{
    cout << "input: s1=" << s1 << ", s2=" << s2;
    vector<string> r = Solution().uncommonFromSentences(s1, s2);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test("apple apple", "banana");
}


// Result 
//
// 2022-12-21: Runtime 0ms 100% Memory 7MB 24.72%, https://leetcode.com/problems/uncommon-words-from-two-sentences/submissions/863006182/



