#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> rst; 
		vector<string> path(s.length(), "");
		_partition(s, 0, s.length(), path, 0, rst);
		return rst;
    }
	
    void _partition(string& s, int pos, int len, vector<string>& path, int size, vector<vector<string>>& rst) {
		if( len == 0 )
            rst.push_back(vector<string>(path.begin(), path.begin()+size));	
		
        for(int i = 0; i < len; ++i)
        	if( isPalindrome(s, pos, pos+i) )
			{	path[size] = s.substr(pos, i+1);
				_partition(s, pos+i+1, len-i-1, path, size+1, rst);
			}
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
// 2023-03-11: Runtime 92ms 96.81% Memory 49.1MB 94.85%, https://leetcode.com/problems/palindrome-partitioning/submissions/913060615/



