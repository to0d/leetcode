#include <lt_help/lt.h>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        m_wordSet.clear();
		m_maxWordLen = -1;
		static char buf1[26], buf2[26], buf3[26]; 
		cal(buf1, s);
		memset(buf3, 0, 26);		
		for(auto w : wordDict)
		{	cal(buf2, w);
			bool match = true;
			for(int i = 0;i < 26; ++i)
			{	if( buf2[i] > buf1[i] )
					match = false;
				buf3[i] += buf2[i];
			}
			if( !match )
				continue;
			m_wordSet.insert(w);
			m_maxWordLen = std::max(m_maxWordLen, (int)w.length());
		}
		for(int i = 0;i < 26; ++i)
		{	if( buf1[i] > 0 && buf3[i] == 0)
			return false;
		}
		return _wordBreak(s.c_str(), s.length());
    }
	
	bool _wordBreak(const char* p, int len) {
		if( len == 0 )
			return true;
		int len2 = std::min(len, m_maxWordLen);
		for(int i = len2; i > 0; --i)
		 	if( m_wordSet.count(string(p, i)) != 0 && _wordBreak(p+i, len-i) )
				return true;
		return false;
	}
    
    void cal(char* buf, string& s) {
        int size = s.length();
        memset(buf, 0, 26);
        for(int i = 0; i < size; ++i)
            buf[s.at(i)-'a']++;
    }
	
	unordered_set<string> m_wordSet;
	int m_maxWordLen;
};



void test(string s, vector<string> wordDict)
{
    cout << "input: s=" << s << ", dict=";
    outputVector(wordDict);
    bool r = Solution().wordBreak(s, wordDict);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test("leetcode", {"leet","code"});
}


// Result 
//
// 2023-01-03: Runtime 10ms 65.70% Memory 7.7MB 87.51%, https://leetcode.com/problems/word-break/submissions/870119684/
// 2023-03-13: Runtime 0ms 100% Memory 7.7MB 88.37%, https://leetcode.com/problems/word-break/submissions/913891237/




