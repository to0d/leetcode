#include <lt_help/lt.h>

int topologicalOrder(int total, vector<vector<int>>& prerequisites, vector<int>& orders) {
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
        orders.push_back(pre);
        ++count;
        for( int next : nextIndexs[pre] )
            if( --preCount[next] == 0 )
                noPreQueue.push( next );
    }

    return count;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses;
        int count = topologicalOrder(numCourses, prerequisites, courses);        
        return count == numCourses ? courses : vector<int>();
    }
};



void test(int numCourses, vector<vector<int>>& prerequisite)
{
    cout << "input: num=" << numCourses << "pre=";
    outputVector(prerequisite);
    vector<int> r = Solution().findOrder(numCourses, prerequisite);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(4, {{1,0},{2,0},{3,1},{3,2}}); 
}


// Result 
//
// 2022-11-24: Runtime 61ms 7.48% Memory 14.6MB 26.5%, https://leetcode.com/problems/course-schedule-ii/submissions/849024852/
// 2023-02-22: Runtime 26ms 52.91% Memory 14.7MB 24.24%, https://leetcode.com/problems/course-schedule-ii/submissions/902634171/
// 2023-03-07: Runtime 25ms 56.16% Memory 14.2MB 34.95%, https://leetcode.com/problems/course-schedule-ii/submissions/910708858/


