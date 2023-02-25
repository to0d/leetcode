#include <lt_help/lt.h>

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if( list1.size() > list2.size())
            return findRestaurant(list2, list1);

        vector<string> rst;
        if(list1.empty() || list2.empty())
            return rst;

        unordered_map<string,int> _map1;
        int idx = 0;
        for(auto s : list1)
            _map1[s] = idx++;
        
        idx = 0;
        int minIdx = list1.size() + list2.size();
        for(auto s : list2)
        {   auto iter = _map1.find(s);
            if( iter != _map1.end() )
            {   int sum = iter->second + idx;
                if( sum < minIdx )
                {   rst.clear();
                    minIdx = sum;
                }
                if( sum == minIdx )
                    rst.push_back(s);
            }
            ++idx;
        }
 
        return rst;
    }
};



void test(vector<string> list1, vector<string> list2)
{
    cout << "input: l1=";
    outputVector(list1);
    cout << ", l2=";
    outputVector(list2);
    vector<string> r = Solution().findRestaurant(list1, list2);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({"happy","sad","good"}, {"sad","happy","good"}); 
}


// Result 
//
// 2022-11-28: Runtime 216ms 25.61% Memory 37.4MB 31.21%, https://leetcode.com/problems/minimum-index-sum-of-two-lists/submissions/850963261/
// 2023-02-25: Runtime 88ms 83.38% Memory 37.7MB 30.31%, https://leetcode.com/problems/minimum-index-sum-of-two-lists/submissions/904435634/


