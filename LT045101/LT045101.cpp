#include <lt_help/lt.h>



bool less_interval(const vector<int>& a, const vector<int>& b)
{   return a[1] > b[1];
}

class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();
        static int buf[256];
        memset(buf, 0, sizeof(buf));
        for(int i = 0; i < len; ++i)
        {   buf[s.at(i)]++;
        }
        vector<vector<int>> freVector;
        for(int i = 0; i < 256; ++i)
        {   int v = buf[i];
            if( v > 0 )
            {   vector<int> vec = {i, v};
                freVector.push_back(vec);
            }
        }
        std::sort(freVector.begin(), freVector.end(), less_interval);
        static char buf2[5*100000];
        int buf2_len = 0;
        for(auto v : freVector)
        {   char c = (char) v[0];
            int num = v[1];
            for(int i = 0; i < num; ++i)
                buf2[buf2_len++] = c;
        }
        return string(buf2, buf2_len);
    }
};

void test(string s)
{
    cout << "input: " << s;
    string r = Solution().frequencySort(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("tree");
}

// Result 
//
// 2023-01-29: Runtime 7ms 96.80% Memory 8.6MB 46.18%, https://leetcode.com/problems/sort-characters-by-frequency/submissions/887387765/

