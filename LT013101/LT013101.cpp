#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> rst; 
		vector<string> path;
		for(int i = 0;i < s.length(); ++i)
			path.push_back("");
		_partition(s.c_str(), s.length(), path, 0, rst);
		return rst;
    }
	
    void _partition(const char* p, int len, vector<string>& path, int size, vector<vector<string>>& rst) {
		//cout << "_partition: p=" << string(p, len) << ", len=" << len << endl;
		if( len == 0 )
		{	if( path.size() == size)
				rst.push_back(path);
			else
			{	vector<string> path2 (path.begin(), path.begin()+size);
				rst.push_back(path2);
			}	
			return;
		}
		for(int i = 1; i <= len; ++i)
		{	if( isPalindrome(p, i) )
			{	path[size] = string(p, i);
				_partition(p+i, len-i, path, size+1, rst);
			}
		}
    }

    bool isPalindrome(const char* p, int len) {
        if( len <= 1 ) 
			return true;
		const char* p2 = p + len -1;
        for(; p < p2; ++p, --p2 )
        {	if( *p != *p2 )
				return false;
        }		
        return true;
    }
};


void test(string s)
{
    cout << "input: " << s;
    vector<vector<string>> r = Solution().partition(s);
    cout << "; output: ";
	outputVector(r);
	cout << ";" << endl;
}

int main(void)
{   test("aab");
}


// Result 
//
// 2022-12-30: Runtime 115ms 80.2% Memory 73.9MB 38.77%, https://leetcode.com/problems/palindrome-partitioning/submissions/867918788/



