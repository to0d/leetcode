#include <lt_help/lt.h>

class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.size(), x = 0, y = 0;
        for( int i = 0; i < len ; ++i)
        {   char c = moves.at(i);
            switch(c)
            {   case 'U': ++y; break;
                case 'D': --y; break;
                case 'L': --x; break;
                case 'R': ++x; break;
            }
        }
        return x == 0 && y == 0;
    }
};



void test(string moves)
{
    cout << "input: " << moves << "; output: ";
    bool r = Solution().judgeCircle(moves);
    cout << r << ";" << endl;
}

int main(void)
{
    test("UD");
}

// Result 
//
// 2022-11-19: Runtime 8ms 58.62% Memory 5.9MB 72.41%, https://leetcode.com/problems/robot-return-to-origin/submissions/846379032/
// 2023-02-25: Runtime 11ms 56.36% Memory 7.9MB 98.48%, https://leetcode.com/problems/robot-return-to-origin/submissions/904433284/
