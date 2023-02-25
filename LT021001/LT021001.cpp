#include <lt_help/lt.h>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> nextCourseMap;
        queue<int> noPreQueue;   
        vector<int> preCount(numCourses,0);
        vector<int> res;

        for( auto pa : prerequisites)
        {   int to = pa[0], from = pa[1];
            if( nextCourseMap.count(from) == 0)
                nextCourseMap[from] = vector<int>();
                nextCourseMap[from].push_back(to);
            preCount[to]++;
        }
        
        for( int c = 0; c < numCourses; ++c)
            if( preCount[c] == 0)
                noPreQueue.push(c);
        
        while( !noPreQueue.empty() )
        {   int c = noPreQueue.front();
            noPreQueue.pop();               
            res.push_back(c);
            
            if( nextCourseMap.count(c))
                for( int to : nextCourseMap[c])
                    if( --preCount[to] == 0 )
                    noPreQueue.push(to);
        }

        if( res.size() != numCourses)
            res.clear();

        return res;
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
    vector<vector<int>> prerequisite = {{1,0},{2,0},{3,1},{3,2}};
    test(4, prerequisite); 
}


// Result 
//
// 2022-11-24: Runtime 61ms 7.48% Memory 14.6MB 26.5%, https://leetcode.com/problems/course-schedule-ii/submissions/849024852/
// 2023-02-22: Runtime 26ms 52.91% Memory 14.7MB 24.24%, https://leetcode.com/problems/course-schedule-ii/submissions/902634171/


