#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> rst;
        vector<int> path, indexs;
        unordered_set<int> visited;
        int target = graph.size() - 1;
        
        path.push_back(0);
        visited.insert(0);
        bool push = true;
                 
        while( !path.empty() )
        {   int cur = path.back();
            if( push )
            {   if( cur == target)
                    rst.push_back(path);

                vector<int>& links = graph[cur];
                int find = -1, len  = links.size();
                for(int i = 0; find == -1 && i < len; ++i)
                {   int next = links[i];
                    if( visited.count(next) == 0 )
                        find = i;
                }

                if( find != -1 )
                {   path.push_back(links[find]);
                    indexs.push_back(find);
                    visited.insert(links[find]);
                }
                else
                    push = false;
            }
            else
            {   if( cur == 0 )
                    break;
                
                visited.erase(cur);
                path.pop_back();
                cur = path.back();
                vector<int>& links = graph[cur];
                int len = links.size(), idx = indexs.back(), find = -1;
                indexs.pop_back();
                for(int i = idx + 1; find == -1 && i < len; ++i)
                {   int next = links[i];
                    if( visited.count(next) == 0 )
                        find = i;
                }

                if( find != -1 )
                {   path.push_back(links[find]);
                    indexs.push_back(find);
                    visited.insert(links[find]);
                    push = true;
                }
            }
        }
        return rst;
    }
};



void test(vector<vector<int>> graph)
{
    cout << "input: "; 
    outputVector(graph); 
    vector<vector<int>> r = Solution().allPathsSourceTarget(graph);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({{1,2},{3},{3},{}});
}

// Result 
//
// 2023-01-18: Runtime 23ms 38.33% Memory 11.7MB 60.97%, https://leetcode.com/problems/all-paths-from-source-to-target/submissions/880452388/
// 2023-02-25: Runtime 15ms 59.40% Memory 11.8MB 60.83%, https://leetcode.com/problems/all-paths-from-source-to-target/submissions/904431807/



