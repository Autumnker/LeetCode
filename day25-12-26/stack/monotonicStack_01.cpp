/**
 * 单调栈 Q1 "商品折扣后的最终价格"
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            ans[i] = prices[i];
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                ans[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> prices = { 8,4,6,2,3 };
    vector<int> ans = sol.finalPrices(prices);
    for (auto item : ans) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
#endif