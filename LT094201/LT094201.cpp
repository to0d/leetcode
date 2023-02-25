#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b){   
    return a[0] < b[0];
}
    
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<vector<int>> tmp;
        tmp.push_back({0, 0});
        int len = s.length();       
        for(int i = 0;i < len; ++i)
        {   char c = s.at(i);
            int v = i+1;
            if( c == 'D' )
                v = -v;
            vector<int> ex = {v, i+1};
            tmp.push_back(ex);
        }

        std::sort(tmp.begin(), tmp.end(), less_interval);
        
        vector<int> rst(len+1, 0);
        int idx = 0;
        for(vector<int>& vec : tmp)
            rst[vec[1]] = idx++;
        
        return rst;
    }
};



void test(string s)
{
    cout << "input: " << s;
    vector<int> r = Solution().diStringMatch(s);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test("IDID");
}


// Result 
//
// 2022-12-22: Runtime 55ms 5.19% Memory 17.9MB 5.2%, https://leetcode.com/problems/di-string-match/submissions/863785726/
// 2023-02-24: Runtime 63ms 5.20% Memory 17.9MB 25.26%, https://leetcode.com/problems/di-string-match/submissions/904200541/



