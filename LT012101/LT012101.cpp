#include <lt_help/lt.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() < 2)
            return 0;
        
        int answer = 0; //At least, you do not need to by stock to loose any money
        int p1 = 0;
        for(int i = 1; i < prices.size(); ++i)
        {   int p2 = prices[i] - prices[i-1];
            p1 = std::max( p2, p1 + p2);
            answer = std::max( answer, p1);
        }

        return answer;
    }
};

   
   
void test(vector<int> prices)
{
    cout << "input: ";
    outputVector(prices);
    int r = Solution().maxProfit(prices);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({7,1,5,3,6,4});
}

// Result 
//
// 2022-11-21: Runtime 271ms 12.69% Memory 93.3MB 56.24%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/847462655/
// 2023-02-22: Runtime 150ms 39.20% Memory 93.4MB 11.86%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/902639546/


