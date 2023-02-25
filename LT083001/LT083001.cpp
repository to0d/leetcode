#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> r;
        int len = s.length(), last = 0;
        for(int i=1; i <= len; ++i)
        {   //cout << "cur=" << s.at(i) << ", last=" << s.at(last) << endl;
            if(i == len || s.at(i) != s.at(last))
            {   if(i >= (last+3) )
                {   vector<int> rr = {last, i-1};
                    r.push_back(rr);
                }
                last = i;
            }
        }
        return r;
    }
};



void test(string s)
{
    cout << "input: " << s;
    vector<vector<int>> r = Solution().largeGroupPositions(s);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test("abbxxxxzzy");
}


// Result 
//
// 2022-12-04: Runtime 4ms 54.52% Memory 7.5MB 11.67%, https://leetcode.com/problems/positions-of-large-groups/submissions/854167493/


