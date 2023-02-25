#include <lt_help/lt.h>

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        stack<char> s;
        
        for(int pos = 0; pos < len; ++pos)
        {   char c = preorder.at(pos++);
            while( !s.empty() && s.top() =='#' && c == '#')
            {   s.pop(); // pop #
                if( s.empty() || s.top() == '#' )
                    return false;
                s.pop();
            }

            s.push(c);
            while( pos < len && preorder.at(pos) != ',')
                ++pos;
        }

        return s.size() == 1 && s.top() == '#';
    }
};



void test(string preorder)
{
    cout << "input: " << preorder;
    bool r = Solution().isValidSerialization(preorder);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("9,3,4,#,#,1,#,#,2,#,6,#,#");
}


// Result 
//
// 2022-11-22: Runtime 7ms 42.72% Memory 6.9MB 64.74%, https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/submissions/848111072/
// 2023-02-22: Runtime 4ms 58.96% Memory 6.9MB 66.60%, https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/submissions/902749404/



