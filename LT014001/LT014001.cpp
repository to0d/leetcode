#include <lt_help/lt.h>



class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> rst;
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
			int wlen = w.length();
			m_maxWordLen = std::max(m_maxWordLen, wlen);
		}
		for(int i = 0;i < 26; ++i)
		{	if( buf1[i] > 0 && buf3[i] == 0)
			return rst;
		}
		static char buf[40];
		int buf_len = 0;
		_wordBreak(s.c_str(), s.length(), buf, buf_len, rst);
		return rst;
    }
	
	void _wordBreak(const char* p, int len, char* buf, int buf_len, vector<string>& rst) {
		if( len == 0 )
		{	string w(buf, buf_len);
			rst.push_back(w);
			return;
		}
		int len2 = std::min(len, m_maxWordLen);
		if( buf_len > 0 )
			buf[buf_len++] = ' ';
		for(int i = len2; i > 0; --i)
		{	string w(p, i);
			//cout << "w: " << w << endl;
			if( m_wordSet.count(w) == 0 )
				continue;
			memcpy(buf+buf_len, p, i);
			_wordBreak(p+i, len-i, buf, buf_len+i, rst);
		}
	}
    void cal(char* buf, string& s)
    {   int size = s.length();
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
    vector<string> r = Solution().wordBreak(s, wordDict);
    cout << "; output: ";
	outputVector(r);
	cout << ";" << endl;
}

int main(void)
{   
    test("catsanddog", {"cat","cats","and","sand","dog"});
}


// Result 
//
// 2023-01-03: Runtime 0ms 100% Memory 7.2MB 85.60%, https://leetcode.com/problems/word-break/submissions/870119684/


