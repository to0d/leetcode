#include <lt_help/lt.h>

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());
        int size = timePoints.size(), minDiff = INT_MAX;
        for(int i = 0; i < size; ++i)
            minDiff = std::min(minDiff, _diff(timePoints[i], timePoints[(i+1)%size]));
        return minDiff;
    }

    int _diff(const string& a, const string& b) {  
        int dh = std::stoi(b.substr(0,2)) - std::stoi(a.substr(0,2));
        int dm = std::stoi(b.substr(3,2)) - std::stoi(a.substr(3,2));
        if( dh < 0 || (dh == 0 && dm < 0) )
        {   dh = -dh;
            dm = -dm;
        }
        int diff = dh*60 + dm;
        if( diff > 12*60 )
            diff = 24*60 - diff;; 
        return diff;
    }
};



void test(vector<string> timePoints)
{
    cout << "input: ";
    outputVector(timePoints);
    int r = Solution().findMinDifference(timePoints);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({"23:59","00:00"});
}

// Result 
//
// 2023-01-15: Runtime 25ms 30.85% Memory 13.3MB 93.97%, https://leetcode.com/problems/minimum-time-difference/submissions/878445319/
// 2023-02-25: Runtime 19ms 50.50% Memory 13.2MB 98.57%, https://leetcode.com/problems/minimum-time-difference/submissions/904438775/




