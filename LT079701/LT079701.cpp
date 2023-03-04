#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        m_rst.clear();
        m_target = graph.size()-1;
        deepVisitGraph(graph, 0);
        return m_rst;
    }

    void visit(vector<vector<int>>& graph, vector<int>& path) {
        int cur_node = path.back();
        if( cur_node == m_target)
            m_rst.push_back(path);
    }

    void deepVisitGraph(vector<vector<int>>& graph, int start) {
        vector<int> path, visited_indexs, visited_nodes(graph.size(), 0);
        path.push_back(start);
        visited_nodes[start] = 1; 
        bool push = true;
                 
        while( !path.empty() )
        {   int cur_node = path.back();
            if( push )
            {   
                visit(graph, path);

                // find next unvisited node
                vector<int>& links = graph[cur_node];
                int find = -1, len  = links.size();
                for(int i = 0; find == -1 && i < len; ++i)
                {   int next = links[i];
                    if( visited_nodes[next] == 0 )
                        find = i;
                }

                if( find != -1 )
                {   path.push_back(links[find]);
                    visited_indexs.push_back(find);
                    visited_nodes[links[find]] = 1;
                }
                else
                    push = false;
            }
            else
            {   if( cur_node == 0 )
                    break;
                
                visited_nodes[cur_node] = 0;
                path.pop_back();
                
                cur_node = path.back();
                vector<int>& links = graph[cur_node];
                int len = links.size(), idx = visited_indexs.back(), find = -1;
                visited_indexs.pop_back();
                for(int i = idx + 1; find == -1 && i < len; ++i)
                {   int next = links[i];
                    if( visited_nodes[next] == 0 )
                        find = i;
                }

                if( find != -1 )
                {   path.push_back(links[find]);
                    visited_indexs.push_back(find);
                    visited_nodes[links[find]] = 1;
                    push = true;
                }
            }
        }
    }
    
    vector<vector<int>> m_rst;
    int m_target;
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
// 2023-03-04: Runtime 13ms 78.97% Memory 11.9MB 60.26%, https://leetcode.com/problems/all-paths-from-source-to-target/submissions/908660294/


