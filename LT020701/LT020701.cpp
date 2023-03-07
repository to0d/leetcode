#include <lt_help/lt.h>

int topologicalOrder(int total, vector<vector<int>>& prerequisites) {
    vector<vector<int>> nextIndexs(total);
    vector<int> preCount(total, 0);
    for( auto p : prerequisites)
    {   nextIndexs[p[1]].push_back(p[0]);
        preCount[p[0]]++;
    }

    queue<int> noPreQueue;   
    for( int i = 0; i < total; ++i)
        if( preCount[i] == 0 )
            noPreQueue.push(i);

    int count = 0;
    while( !noPreQueue.empty() )
    {   int pre = noPreQueue.front(); noPreQueue.pop();
        ++count;
        for( int next : nextIndexs[pre] )
            if( --preCount[next] == 0 )
                noPreQueue.push( next );
    }

    return count;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = topologicalOrder(numCourses, prerequisites);   
        return count == numCourses;
    }
};


   
void test(int numCourses, vector<vector<int>> prerequisites)
{
    cout << "input: num=" << numCourses << ", pre=";
    outputVector(prerequisites);
    bool r = Solution().canFinish(numCourses, prerequisites);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(2, {{1,0}});
}

// Result 
//
// 2022-11-23: Runtime 76ms 6.4% Memory 15.1MB 18.4%, https://leetcode.com/problems/course-schedule/submissions/848547625/
// 2023-02-22: Runtime 51ms 11.28% Memory 15.2MB 17.79%, https://leetcode.com/problems/course-schedule/submissions/902630983/
// 2023-03-07: Runtime 20ms 84.83% Memory 14.1MB 43.84%, https://leetcode.com/problems/course-schedule/submissions/910710403/

