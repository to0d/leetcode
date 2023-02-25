#include <lt_help/lt.h>



class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> _map1;
        unordered_map<string,string> _map2;
        string fromCity, toCity;
        for( vector<string>& path : paths )
        {   fromCity = path[0];
            toCity   = path[1];
            while(true)
            {   auto it1 = _map1.find(toCity);
                if( it1 != _map1.end() )
                {   toCity = it1->second;
                    _map1.erase(it1);
                    continue;
                }
                auto it2 = _map2.find(fromCity);
                if( it2 != _map2.end() )
                {   fromCity = it2->second;
                    _map2.erase(it2);
                    continue;
                }
                break;
            }
            _map1[fromCity] = toCity;
            _map2[toCity] = fromCity;
        }
        return toCity;
    }
};


void test(vector<vector<string>> paths)
{
    cout << "input: ";
    outputVector(paths);
    string r = Solution().destCity(paths);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{"B","C"},{"D","B"},{"C","A"}});
}


// Result 
//
// 2022-12-20: Runtime 11ms 84.92% Memory 10.9MB 46.28%, https://leetcode.com/problems/destination-city/submissions/862436992/



