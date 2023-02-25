#include <lt_help/lt.h>



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rst;
        for(string& word : words)
        {   int len = word.length();
            if( len == 0 )
                continue;
            int level = _level(word.at(0));            
            for(int i = 1; level != -1 && i < len; ++i)
            {   if( _level(word.at(i)) != level )
                    level = -1;
            }
            if( level != -1 )
               rst.push_back(word); 
        }
        return rst;
    }
    static int _level(char c)
    {   return m_cmap[tolower(c)-'a'];
    }
    
static const char m_cmap[26];
};

// qwertyuiop
// asdfghjkl
// zxcvbnm
//
const char Solution::m_cmap[26] = 
// a b c d e f g h i j k l m n o p q r s t u v w x y z
  {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};



void test(vector<string> words)
{
    cout << "input: ";
    outputVector(words);
    vector<string> r = Solution().findWords(words);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test({"Hello","Alaska","Dad","Peace"});
}


// Result 
//
// 2023-01-09: Runtime 0ms 100% Memory 6.8MB 65.83%, https://leetcode.com/problems/keyboard-row/submissions/874793421/


