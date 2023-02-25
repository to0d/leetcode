#include <lt_help/lt.h>



class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        static char buf[100];
        int len = s.length();
        for(int i = 0;i < len; ++i)
            buf[indices[i]] = s.at(i);
        return string(buf, len);
    }
};


void test(string s, vector<int> indices)
{
    cout << "input: s=" << s << ", indices=";
    outputVector(indices);
    string r = Solution().restoreString(s, indices);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("codeleet", {4,5,6,7,0,2,1,3});
}


// Result 
//
// 2022-12-15: Runtime 7ms 83.19% Memory 15.1MB 94.71%, https://leetcode.com/problems/shuffle-string/submissions/859978785/


