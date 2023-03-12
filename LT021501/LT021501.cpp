#include <lt_help/lt.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if( k == 1 )
        {   int mv = INT_MIN;
            for(int num : nums )
                mv = std::max(mv, num);
            return mv;        
        }

        vector<int> heap;
        for(int num : nums )
            pushHeap(heap, k, num);                
        return heap[0];       
    }

    void pushHeap(vector<int>& heap, int k, int v) {
        if( heap.size() == (size_t)k )
        {   if( v <= heap[0] ) 
                return; 
            //Adjust Heap
            heap[0] = v;
            adjustHeap(heap, k, 0 );
        }
        else
        {   heap.push_back(v);
            // Build Heap
            if( heap.size() == (size_t)k )
            {   for(int pos = k/2-1; pos >= 0; --pos)
                {   int posL = 2*pos+1, posR = posL+1;
                    if( heap[posL] < heap[pos] )
                    {   swap( heap, posL, pos);
                        adjustHeap(heap, k , posL);
                    }
                    if(posR < k && heap[posR] < heap[pos] )
                    {   swap( heap, posR, pos);
                        adjustHeap(heap, k , posR);
                    }
                }
            }
        }
    }

    void adjustHeap(vector<int>& heap, int k, int pos) {
        while (pos <= (k/2-1))
        {   int child = 2*pos+1;
            if( (child + 1) < k && heap[child] > heap[child+1])
                ++child;
            if( heap[pos] <= heap[child])
                break;
            swap( heap, pos, child);
            pos = child;
        }
    }

    void swap(vector<int>& heap, int a, int b) {
        int t = heap[a];
        heap[a] = heap[b];
        heap[b] = t;
    }
};


   
void test(vector<int> nums, int k)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", k=" << k;
    int r = Solution().findKthLargest(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({3,2,1,5,6,4}, 2);
}

// Result 
//
// 2022-11-21: Runtime 317ms 5.2% Memory 47.3MB 33.85%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/847518374/
// 2023-03-12: Runtime 154ms 21.39% Memory 47.4MB 34.8%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/913852520/

