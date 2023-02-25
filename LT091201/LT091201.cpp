#include <lt_help/lt.h>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void mergeSort(vector<int>& nums, int start, int end){
        if( start >= end )
            return;
        
        int mid = (start+end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        
        m_temp_len = 0;
        int pos1 = start, pos2 = mid+1;
        while( pos1 <= mid && pos2 <= end )
        {   int v1 = nums[pos1], v2 = nums[pos2];
            if( v1 <= v2 )
            {   _add_temp(v1);
                ++pos1;
            }
            else
            {   _add_temp(v2);
                ++pos2;
            }
        }

        for(; pos1 <= mid; ++pos1)
            _add_temp(nums[pos1]);

        for(; pos2 <= end; ++pos2 )
            _add_temp(nums[pos2]);

        for(int i = 0; i < m_temp_len; ++i)
            nums[start+i] = m_temp[i];
    }
    
    void _add_temp(int v){  
        if( m_temp.size() == m_temp_len )
            m_temp.push_back(v);
        else
            m_temp[m_temp_len] = v;
        m_temp_len++;
    }
    
    vector<int> m_temp;
    int m_temp_len;
};


void test(vector<int> nums)
{
    cout << "input: "; 
    outputVector(nums); 
    vector<int> r = Solution().sortArray(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({5,2,3,1});
}

// Result 
//
// 2023-01-31: Runtime 236ms 49.78% Memory 62.1MB 48.31%, https://leetcode.com/problems/sort-an-array/submissions/888654862/
// 2023-02-18: Runtime 260ms 45.49% Memory 66.2MB 37.29%, https://leetcode.com/problems/sort-an-array/submissions/900119788/


