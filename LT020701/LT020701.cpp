#include <lt_help/lt.h>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> nextMap;
        unordered_map<int, int > preMap;
        queue<int> noPreQueue;
        int visitedCourse = 0 ;

        for( auto p : prerequisites)
        {   nextMap[p[0]].push_back(p[1]);
            preMap[p[1]]++;
        }
        
        for( int i = 0; i < numCourses; ++i)
            if( preMap[i] == 0 )
                noPreQueue.push(i);
        
        while( !noPreQueue.empty() )
        {   int course = noPreQueue.front();
            noPreQueue.pop();
            ++visitedCourse;
            for( int next : nextMap[course] )
                if( --preMap[next] == 0 )
                    noPreQueue.push( next);
        }

        return visitedCourse == numCourses;
    }
};
    

   
void test(int numCourses, vector<vector<int>>& prerequisites)
{
    cout << "input: num=" << numCourses << ", pre=";
    outputVector(prerequisites);
    bool r = Solution().canFinish(numCourses, prerequisites);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    vector<vector<int>> prerequisites = {{1,0}};
    test(2, prerequisites);
}

// Result 
//
// 2022-11-23: Runtime 76ms 6.4% Memory 15.1MB 18.4%, https://leetcode.com/problems/course-schedule/submissions/848547625/
// 2023-02-22: Runtime 51ms 11.28% Memory 15.2MB 17.79%, https://leetcode.com/problems/course-schedule/submissions/902630983/


