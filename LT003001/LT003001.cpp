#include <lt_help/lt.h>

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, vector<int>> _map;
        int word_size = words.size(), word_len = words[0].length();

        for(int i = 0;i < word_size; ++i)
        {   auto iter = _map.find(words[i]);
            if( iter == _map.end())
                _map[words[i]] = {i};
            else
                iter->second.push_back(i);
        }

        vector<int> rst;        
        int len = s.length() - word_size*word_len;
        for(int i = 0; i <= len ; ++i)
        {   vector<int> used(word_size, -1); 
            bool unmatch = false;
            for(int j = 0; !unmatch && j < word_size; ++j)
            {   auto iter = _map.find(s.substr(i+j*word_len, word_len));
                if( iter == _map.end())
                    unmatch = true;
                else
                {   vector<int>& idxs = iter->second;
                    bool find = false;
                    for(int k = 0 ; !find && k < idxs.size(); ++k)
                    {   int idx = idxs[k];
                        if( used[idx] == -1 )
                        {   used[idx] = 1;
                            find = true;
                        }                        
                    }
                    if( !find )
                        unmatch = true;
                }
            }
            if(!unmatch)
                rst.push_back(i);
        }

        return rst;
    }
};



void test(string s, vector<string> words)
{
    cout << "input: s=" << s << ", words=";
    outputVector(words);
    vector<int> r = Solution().findSubstring(s, words);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test("barfoothefoobarman", {"foo","bar"});
}


// Result 
//
// 2022-12-05: Runtime 1256ms 16.99% Memory 35.4MB 57.18%, https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/854859260/
// 2023-02-16: Runtime 668ms 45.48% Memory 35.2MB 59.49%, https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/899199973/



