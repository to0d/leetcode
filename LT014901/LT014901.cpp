#include <lt_help/lt.h>



class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        if( size <= 2)
            return size;        
        unordered_map<int,vector<unordered_set<int>>> _lineMap;
        int _max = 2;
        for(int i = 0;i < size-2; ++i)
        {   int x0 = points[i][0], y0 = points[i][1];
            for(int j = i+1; j < size-1; ++j)
            {   bool found = false;
                auto it = _lineMap.find(i);
                if( it != _lineMap.end())
                {   for( auto _set : it->second )
                    {   if( _set.count(j) != 0 )
                        {   found = true;
                            break;
                        }
                    }
                }
                if( found )
                    continue;
                 
                int dx1 = points[j][0] - x0, dy1 = points[j][1] - y0;
                int _max2 = 2;
                unordered_set<int> _set;
                _set.insert(i);
                _set.insert(j);
                for(int k = j+1; k < size; ++k)
                {   if((points[k][0] - x0)*dy1 == dx1*(points[k][1] - y0))
                    {   ++_max2;
                        _set.insert(k);
                        //cout << i << " " << j << " " << k << endl;
                    }
                }
                if( _max2 > 2 )
                {   for(int idx : _set )
                    {   auto it = _lineMap.find(idx);
                        if( it != _lineMap.end())
                            it->second.push_back(_set);
                        else
                        {   vector<unordered_set<int>> vec = {_set};
                            _lineMap[idx] = vec;
                        }
                    }
                }
                _max = std::max(_max, _max2);
            }
        }
        return _max;
    }
};


void test(vector<vector<int>> points)
{
    cout << "input: ";
    outputVector(points);
    int r = Solution().maxPoints(points);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({{1,1},{2,2},{3,3}});
}


// Result 
//
// 2023-01-04: Runtime 627ms 5.31% Memory 86.2MB 5.21%, https://leetcode.com/problems/max-points-on-a-line/submissions/870850402/


