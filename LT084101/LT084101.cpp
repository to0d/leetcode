#include <lt_help/lt.h>



class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num = rooms.size(), count = 0;
        vector<int> visited(num, 0);
        queue<int> vq;
        vq.push(0);
        while(!vq.empty())
        {   int idx = vq.front();
            vq.pop();
            if( visited[idx] != 0 )
                continue;
            visited[idx]++;
            count++;
            for(int next : rooms[idx])
                vq.push(next);
        }
        return count == num;
    }
};

void test(vector<vector<int>> rooms)
{
    cout << "input: "; 
    outputVector(rooms); 
    bool r = Solution().canVisitAllRooms(rooms);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({{1},{2},{3},{}});
}

// Result 
//
// 2023-01-29: Runtime 7ms 95.75% Memory 10.6MB 20.19%, https://leetcode.com/problems/keys-and-rooms/submissions/887520954/


