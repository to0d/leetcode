#include <lt_help/lt.h>

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        linkedList.clear();
        linkedList.push_back(beginWord);
        depth = 2; comparePosBegin = 0; comparePosEnd = 1;
        
        vector<string> words;
        for(auto it = wordList.begin(); it != wordList.end(); ++it)
            if(endWord != *it)
                words.push_back(*it);
        
        if( words.size() == wordList.size()) // endWord is not in wordList
            return false;
                
        while(comparePosBegin < comparePosEnd )
        {   if( tryLink(endWord))
                return depth;

            auto it = words.begin();
            while(it != words.end())
                if( tryLink(*it))
                   it= words.erase(it);
               else
                   it++;

            depth++; 
            comparePosBegin = comparePosEnd;
            comparePosEnd   = (int) linkedList.size();
        }

        return 0;
    }
    
private:

    bool tryLink(const string& word ) {
        for( int i = comparePosBegin; i < comparePosEnd; ++i)
            if( isLink( linkedList[i], word ) )
            {   linkedList.push_back(word);
                return true;
            }
        return false;
    }

    bool isLink(const string& from, const string& to ){
        int len = from.size(), count = 0;
        for(int i = 0 ;i < len; ++ i)
           if( from.at(i) != to.at(i) )
               if( ++count > 1) 
                   return false;;      
        return count == 1;
    }
    
    int depth;
    int comparePosBegin;
    int comparePosEnd;
    vector<string> linkedList;
};

void test(string beginWord, string endWord, vector<string> wordList)
{
    cout << "input: begin=" << beginWord << ", end=" << endWord << ", list=";
    outputVector(wordList);
    int r = Solution().ladderLength(beginWord, endWord, wordList);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("hit", "cog", {"hot","dot","dog","lot","log","cog"});
}


// Result 
//
// 2023-07-31: Runtime 440ms 23.97% Memory 15.30MB 36.57%, https://leetcode.cn/problems/word-ladder/submissions/451922055/



