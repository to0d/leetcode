#include <lt_help/lt.h>

class Solution {
public:

    bool wordPattern(string pattern, string str){
        unordered_map<char,string> psMap;
        unordered_map<string,char> spMap;

        m_posOfPattern = 0;
        m_posOfString  = 0;
        m_pattern = pattern;
        m_str = str;
        
        char c;
        string* s;

        while( (c = nextPattern()) != 0 )
        {   if( (s = nextString()) == NULL )
                return false;
            
            auto psIter = psMap.find(c);
            auto spIter = spMap.find(*s);
            if( psIter == psMap.end() )
            {   if( spIter == spMap.end() )
                {   psMap.insert(std::make_pair(c,*s));
                    spMap.insert(std::make_pair(*s,c));
                }
                else
                    return false;
            }
            else if( spIter == spMap.end() )
                return false;
            else
            {   if( psIter->second != *s || spIter->second != c)
                    return false;
            }
        }

        return c != 0 || nextString() == NULL;
    }
   
    char nextPattern(){
         while( m_posOfPattern < m_pattern.size() && m_pattern[m_posOfPattern] == ' ')
            ++m_posOfPattern;

         char c = m_posOfPattern < m_pattern.size() ? m_pattern[m_posOfPattern] : 0 ;
         ++m_posOfPattern;
         return c;
    }
    
    string* nextString(){
        while( m_posOfString < m_str.size() && m_str[m_posOfString] == ' ')
            ++m_posOfString;  
        
        if( m_posOfString >= m_str.size() )
            return NULL;

        int pEnd = m_posOfString+1;
        while( pEnd < m_str.size() && m_str[pEnd] != ' ')
            ++pEnd;
           
        int len = pEnd - m_posOfString;
        m_aString = string(m_str.c_str() + m_posOfString, len);
        m_posOfString = pEnd + 1;
        return &m_aString;
    }
    
    string m_pattern;
    string m_str;
    string m_aString;
    
    int    m_posOfPattern;
    int    m_posOfString;
};



void test(string pattern, string str)
{
    cout << "input: pattern=" << pattern << ", s=" << str;
    bool r = Solution().wordPattern(pattern, str);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("abba", "dog cat cat dog");
}

// Result 
//
// 2022-11-22: Runtime 4ms 37.42% Memory 6.4MB 62.3%, https://leetcode.com/problems/word-pattern/submissions/847761286/
// 2023-02-22: Runtime 4ms 37.50% Memory 6.5MB 62.11%, https://leetcode.com/problems/word-pattern/submissions/902734707/


