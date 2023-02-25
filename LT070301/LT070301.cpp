#include <lt_help/lt.h>



class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for(int v : nums)
            _push(v);
    }
    
    int add(int val) {
        _push(val);
        return m_heap[0];
    }
    
    void _push(int val)
    {   // cout << "Push: " << v << endl; 
        if( m_heap.size() == m_k )
        {   if(val <= m_heap[0] ) 
                return;
            m_heap[0] = val;
            _adjustHeap(0);
        }
        else
        {   m_heap.push_back(val);
            // Build Heap
            if( m_heap.size() == m_k )
            {   for(int pos = m_k/2-1; pos >= 0; --pos)
                {   int posL = 2*pos+1, posR = posL+1;
                    if( m_heap[posL] < m_heap[pos])
                    {   _swap( posL, pos);
                        _adjustHeap( posL );
                    }
                    
                    if( posR < m_k && m_heap[posR] < m_heap[pos])
                    {   _swap( posR, pos);
                        _adjustHeap( posR );
                    }
                }
            }
        }
    }
    
    void _adjustHeap(int pos)
    {   while (pos <= (m_k/2-1))
        {   int child = 2*pos+1; 
            if( (child + 1) < m_k && m_heap[child] > m_heap[child+1] )
                ++child;
            if( m_heap[pos] <= m_heap[child] )
                break;
            _swap( pos, child);
            pos = child;
        }
    }
    
    void _swap(int a, int b)
    {   int index = m_heap[a];
        m_heap[a] = m_heap[b];
        m_heap[b] = index;
    }
    
    vector<int> m_heap;
    int m_k;
};


void test(int k, vector<int> nums)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    KthLargest solution(k, nums);
    int r = solution.add(0);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3, {4, 5, 8, 2});
}

// Result 
//
// 2023-01-10: Runtime 39ms 54.42% Memory 19.9MB 50.77%, https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/875517214/

