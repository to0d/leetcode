#include <lt_help/lt.h>

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if( start == destination )
            return 0;
        
        int size = distance.size();
        if( start >= size || destination >= size)
            return distanceBetweenBusStops(distance, start%size, destination%size);
        
        if( start > destination )
            return distanceBetweenBusStops(distance, destination, start);
        
        int a = 0, b = 0;
        for(int i = start; i < destination; ++i)
            a += distance[i];
        for(int i = destination; i < (start+size); ++i)
            b += distance[i%size];
        
        return std::min(a, b);
    }
};


void test(vector<int> distance, int start, int destination)
{
    cout << "input: s=" << start << ", d=" << destination;
    outputVector(distance);
    int r = Solution().distanceBetweenBusStops(distance, start, destination);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,3,4}, 0, 1);
}


// Result 
//
// 2022-12-12: Runtime 11ms 6.52% Memory 8.8MB 56.40%, https://leetcode.com/problems/distance-between-bus-stops/submissions/858397178/
// 2023-02-24: Runtime 4ms 76.58% Memory 8.7MB 57.38%, https://leetcode.com/problems/distance-between-bus-stops/submissions/904203229/



