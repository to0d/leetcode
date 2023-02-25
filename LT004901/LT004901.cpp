#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> groupMap;
        for( auto s : strs)
        {   string key = getKey(s);
            if( groupMap.count( key ) == 0 )
                groupMap[key] = vector<string>();
            groupMap[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for( auto pm : groupMap )
        {   vector<string>& group = (pm).second;
            std::sort( group.begin(), group.end(), std::less<string>());
            res.push_back(group);
        }

        return res;
    }
        
    string getKey(const string& str){
        static char buf [1024];
        int len = str.size();
        strncpy( buf, str.c_str(), len);
        std::sort( buf, buf + len, std::less<char>());
        return string( buf, buf + len);
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


