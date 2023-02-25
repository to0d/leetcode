#include <lt_help/lt.h>



class Solution {
public:
    int minCut(string s) {
		m_minCut.clear();
		for(int i = 0;i <= s.length(); ++i)
			m_minCut.push_back(-1);
        return _minCut(s.c_str(), s.length());
    }

    int _minCut(const char* p, int len) {
		//cout << "_minCut: s=" << string(p, len) << ", max_cut=" << max_cut << endl;
		int min_cut = m_minCut[len];
		if( min_cut == -1 )
		{	min_cut = INT_MAX;
			for(int i = len; i > 0; --i)
			{	if( isPalindrome(p, i) )
				{	if( i == len )
						return 0;
					int sub_cut = _minCut(p + i, len - i);
					min_cut = std::min(min_cut, 1+sub_cut);
				}
			}
			m_minCut[len] = min_cut;
		}
		return min_cut;
    }

    bool isPalindrome(const char* p, int len) {
		//cout << "isPalindrome: s=" << string(p, len) << endl;
        if( len <= 1 ) 
			return true;
		const char* p2 = p + len -1;
        for(; p < p2; ++p, --p2 )
        {	if( *p != *p2 )
				return false;
        }		
        return true;
    }
	vector<int> m_minCut;
};


void test(string s)
{
    cout << "input: " << s;
    int r = Solution().minCut(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("aaabaa");
}


// Result 
//
// 2022-12-30: Runtime 277ms 63.98% Memory 6.4MB 89.66%, https://leetcode.com/problems/palindrome-partitioning-ii/submissions/867862602/



