#include <lt_help/lt.h>



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size(); 
        vector<int> provinces;
        for(int i = 0; i < size; ++i)
            provinces.push_back(i);
        
        for(int i = 0; i < size; ++i)
        {   int idx1 = provinces[i];
            for(int j = i+1; j < size; ++j)
            {   if( isConnected[i][j] == 0 )
                    continue;
                int idx2 = provinces[j];
                if( idx1 == idx2)
                    continue;
                for(int k = 0; k < size; ++k)
                {   if( provinces[k] == idx2 )
                        provinces[k] = idx1;
                }
            }
        }
        
        // for(int p : provinces ) cout << " " << p ; cout << endl;
        std::sort(provinces.begin(), provinces.end());
        int count = 0, last = -1;
        for(int p : provinces )
        {   if( last != p )
            {   last = p;
                ++count;
            }
        }

        return count;
    }
};


void test(vector<vector<int>> isConnected)
{
    cout << "input: ";
    outputVector(isConnected);
    int r = Solution().findCircleNum(isConnected);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({{1,1,0},{1,1,0},{0,0,1}});
}

// Result 
//
// 2023-01-15: Runtime 25ms 72.8% Memory 13.8MB 76.60%, https://leetcode.com/problems/number-of-provinces/submissions/878483950/


