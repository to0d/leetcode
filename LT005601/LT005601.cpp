#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if( intervals.size() < 2 )
            return intervals;

        std::sort(intervals.begin(), intervals.end(), less_interval);

        int i = 0, len = intervals.size();
        for(int j = 1; j < len ; ++j)
        {   vector<int>& a = intervals[i], &b = intervals[j];
            if( b[0] > a[1] )
            {   if( ++i != j )
                    intervals[i] = b;
            }
            else if( b[1] > a[1] ) 
                a[1] = b[1];
        }
        
        if( i < (len - 1) ) 
            intervals.erase(intervals.begin() + i + 1, intervals.end()); 

        return intervals;
    }
};
            


void test(vector<vector<int>> intervals)
{
    cout << "input: ";
    outputVector(intervals);
    vector<vector<int>> r = Solution().merge(intervals);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({{1,3},{2,6},{8,10},{15,18}}); 
}


// Result 
//
// 2022-11-24: Runtime 103ms 11.21% Memory 19.4MB 44.57%, https://leetcode.com/problems/merge-intervals/submissions/849014576/
// 2023-02-17: Runtime 33ms 94.93% Memory 18.4MB 99.23%, https://leetcode.com/problems/merge-intervals/submissions/899822544/


