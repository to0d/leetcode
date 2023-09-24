#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> gm;
        char buf[10000];
        for(auto str : strs) {
            int len = str.length();
            strncpy(buf, str.c_str(), len);
            sort(buf, buf+len);
            string key = string(buf, len);
            gm[key].push_back(str);
        }
        vector<vector<string>> rst;
        for( auto p : gm )
            rst.push_back(p.second); 
        return rst;
    }
};


void test(vector<string> strs)
{
    cout << "input: ";
    outputVector(strs); 
    vector<vector<string>> r = Solution().groupAnagrams(strs);
    cout << "; output: "; 
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({"eat","tea","tan","ate","nat","bat"});
}

// Result 
//
// 2022-11-16: Runtime 105ms 15.88% Memory 20.8MB 46.99%, https://leetcode.com/problems/group-anagrams/submissions/844606184/
// 2023-02-17: Runtime 51ms 37.14% Memory 20.8MB 35.19%, https://leetcode.com/problems/group-anagrams/submissions/899810760/
// 2023-03-15: Runtime 39ms 64.38% Memory 20.8MB 47.40%, https://leetcode.com/problems/group-anagrams/submissions/915735096/
// 2023-09-24: Runtime 40ms 31.87% Memory 20.47MB 16.29%, https://leetcode.cn/problems/group-anagrams/submissions/469190020/


