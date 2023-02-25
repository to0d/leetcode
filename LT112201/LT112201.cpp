#include <lt_help/lt.h>

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> _map;
        for(int v : arr2)
            _map[v] = 0;
        
        int size = arr1.size(), pos1 = 0, pos2 = size - 1;
        while( pos1 <= pos2 )
        {   int v1 = arr1[pos1];
            auto it1 = _map.find(v1);
            if( it1 != _map.end() )
            {   int count = it1->second;
                _map[v1] = count + 1;
                ++pos1;
                continue;
            }
            int v2 = arr1[pos2];
            auto it2 = _map.find(v2);
            if( it2 == _map.end() )
            {   --pos2;
                continue;
            }
            arr1[pos1] = v2;
            arr1[pos2] = v1;
        }

        int pos = 0;
        for(int v : arr2)
        {   auto it = _map.find(v);
            int count = it->second;
            for(int i = 0;i < count; ++i)
                arr1[pos++] = v;
        }

        std::sort(arr1.begin()+pos1, arr1.end());
        return arr1;
    }
};



void test(vector<int> arr1, vector<int> arr2)
{
    cout << "input: arr1=";
    outputVector(arr1);
    cout << ", arr2=";
    outputVector(arr2);
    vector<int> r = Solution().relativeSortArray(arr1, arr2);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({28,6,22,8,44,17}, {22,28,8,6});
}


// Result 
//
// 2022-12-11: Runtime 7ms 33.97% Memory 7.8MB 73.64%, https://leetcode.com/problems/relative-sort-array/submissions/857857395/
// 2023-02-18: Runtime 3ms 77.64% Memory 7.8MB 54.75%, https://leetcode.com/problems/relative-sort-array/submissions/900114872/



