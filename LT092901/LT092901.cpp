#include <lt_help/lt.h>



class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> _set;
        for(string email : emails)
        {   email = _validEmail(email);
            if(email.length() != 0)
                _set.insert(email);
        }
        return _set.size();
    }
    
    string _validEmail(string email)
    {   static char buf[100];
        int buf_len = 0;
        int len = email.length();
        int stage = 0;
        for(int i = 0; i < len;++i )
        {   char c = email.at(i);
            if( stage == 0 )  // local name
            {   switch(c)
                {   case '+': stage = 1; break;
                    case '@': buf[buf_len++] = c; stage = 2; break;
                    case '.': break;
                    default : buf[buf_len++] = c; break;
                }
            } else if ( stage == 1 )
            {   if(c == '@')
                {   buf[buf_len++] = c; 
                    stage = 2;
                }
            } else // stage = 2
            {   buf[buf_len++] = c;
            }
        }
        
        return stage == 2 ? string(buf, buf_len) : "";
    }
};



void test(vector<string> emails)
{
    cout << "input: ";
    outputVector(emails);
    int r = Solution().numUniqueEmails(emails);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({"a.x@bc.c", "ax@bc.c"});
}


// Result 
//
// 2022-12-04: Runtime 27ms 64.76% Memory 14.9MB 28.66%, https://leetcode.com/problems/unique-email-addresses/submissions/854377745/


