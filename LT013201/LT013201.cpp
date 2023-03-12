#include <lt_help/lt.h>

// f(i) = min(f(j)) + 1 where j > i, and s[i..j-1] is palind
class Solution {
public:
    int minCut(string s) {
		vector<int> cache(s.length(), -1);
        return _minCut(s, 0, s.length(), cache);
    }

    int _minCut(string& s, int i, int len, vector<int>& cache) {
		int min_cut = cache[i];
		if( min_cut == -1 )
		{	min_cut = INT_MAX;
            for(int j = len; min_cut > 0 && j > 0; --j)
			 	if( isPalindrome(s, i, i+j-1) )
				{	if( j == len )
                        min_cut = 0;
                    else
                    {   int sub_cut = _minCut(s, i + j, len - j, cache);
                        min_cut = std::min(min_cut, 1+sub_cut);
                    }
				}
			cache[i] = min_cut;
		}
		return min_cut;
    }

    bool isPalindrome(string& s, int low, int high){
        for (; low < high; ++low, --high)
            if( s[low] != s[high] )
                return false;
        return true;
    }
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
// 2023-03-11: Runtime 248ms 65.54% Memory 6.6MB 76.44%, https://leetcode.com/problems/palindrome-partitioning-ii/submissions/913073530/



