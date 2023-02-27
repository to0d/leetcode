#include <lt_help/lt.h>

class Solution {
public:
    Solution(vector<int>& nums) {
        std::copy(nums.begin(), nums.end(), std::back_inserter(m_orginalNums));
    }
    
    vector<int> reset() {
        return m_orginalNums;
    }
    
    vector<int> shuffle() {
        int size = m_orginalNums.size();
        vector<int> randomNums;
        vector<int> usedIndex(size, 0);

        for(int i = 0; i<size; ++i)
        {   int randomIndex = rand() % size;
            while( usedIndex[randomIndex] != 0 )
            {   randomIndex = rand() % size;
            }
            usedIndex[randomIndex] = 1;
            randomNums.push_back(m_orginalNums[randomIndex]);
        }
        return randomNums;         
    }
    
    vector<int> m_orginalNums; 
};



int main(void)
{
    cout << "output: done!" << endl;
}

// Result 
//
// 2023-02-05: Runtime 94ms 19.69% Memory 59.2MB 5.3%, https://leetcode.com/problems/shuffle-an-array/submissions/892027305/
// 2023-02-27: Runtime 76ms 46.62% Memory 59.3MB 5.39%, https://leetcode.com/problems/shuffle-an-array/submissions/905731978/



