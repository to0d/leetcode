#include <lt_help/lt.h>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size(), _max = 0, max_count = 0;
        vector<int> counter(26, 0);
        for( char task : tasks )
        {   int num = ++(counter[(int)(task-'A')]);
            if( _max == num )
                ++max_count;
            else if ( _max < num )
            {   _max = num;
                max_count = 1;
            }
        }
            
        int partCount  = _max - 1;
        int partLength = n - (max_count - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = size - _max * max_count;
        int idles = max(0, emptySlots - availableTasks);
        return size + idles;
    }
};



void test(vector<char> tasks, int n)
{
    cout << "input: n=" << n << ", task=";
    outputVector(tasks);
    int r = Solution().leastInterval(tasks, n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({'A','A','A','B','B','B'}, 2);
}


// Result 
//
// 2023-03-11: Runtime 55ms 98.18% Memory 34.5MB 74.55%, https://leetcode.com/problems/task-scheduler/submissions/913104856/, https://leetcode.com/problems/task-scheduler/solutions/104500/java-o-n-time-o-1-space-1-pass-no-sorting-solution-with-detailed-explanation/


