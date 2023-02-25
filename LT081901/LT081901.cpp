#include <lt_help/lt.h>

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        _fill(words, paragraph);
        
        unordered_set<string> bannedSet;
        for( string b : banned ) 
            bannedSet.insert(b);
        
        unordered_map<string, int> wordMap;
        string maxWord;
        int maxCount = 0;
        for( string word : words )
        {   if( bannedSet.count(word) != 0 )
                continue;
            int count = 0;
            auto iter = wordMap.find(word);
            if( iter != wordMap.end() )
                count = iter->second;
            if( ++count > maxCount )
            {   maxCount = count;
                maxWord  = word;
            }
            wordMap[word] = count;
        }
        
        return maxWord;
    }
    
    void _fill(vector<string>& v, string s) {   
        static char buf[200];
        int buf_len = 0, len = s.length();
        for(int i=0; i <= len; ++i)
        {   char c = (i == len? ' ' : tolower(s.at(i)));
            if( c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.')  // !?',;.
            {   if( buf_len > 0 )
                    v.push_back(string(buf, buf_len));
                buf_len = 0;
            }
            else
                buf[buf_len++] = c;           
        }
    }
};



void test(string paragraph, vector<string> banned)
{
    cout << "input: paragraph=" << paragraph << ", banned=";
    outputVector(banned);
    string r = Solution().mostCommonWord(paragraph, banned);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("Bob hit a ball, the hit BALL.", {"hit"});
}

// Result 
//
// 2023-01-11: Runtime 9ms 27.88% Memory 9.3MB 7.94%, https://leetcode.com/problems/most-common-word/submissions/876171361/
// 2023-02-25: Runtime 5ms 54.64% Memory 9.2MB 10.6%, https://leetcode.com/problems/most-common-word/submissions/904431351/


