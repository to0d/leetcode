#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
        intervals.push_back( newInterval );        
        return merge(intervals);
    }
    
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



void test(vector<vector<int>> intervals, vector<int> newInterval)
{
    cout << "input: intervals=";
    outputVector(intervals);
    cout << ", newInterval=";
    outputVector(newInterval);
    vector<vector<int>> r = Solution().insert(intervals, newInterval);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({{1,3},{6,9}}, {2,5}); 
}


// Result 
//
// 2022-11-24: Runtime 80ms 5.29% Memory 17.8MB 8.54%, https://leetcode.com/problems/insert-interval/submissions/849016957/
// 2023-02-17: Runtime 33ms 13.1% Memory 17.2MB 25.46%, https://leetcode.com/problems/insert-interval/submissions/899824122/


