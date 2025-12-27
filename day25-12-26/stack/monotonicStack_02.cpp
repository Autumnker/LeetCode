/**
 * 单调栈 Q2 "每日温度"
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                ans[stk.top()] = i - stk.top();
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

    vector<int> prices = { 73,74,75,71,69,72,76,73 };
    vector<int> ans = sol.dailyTemperatures(prices);
    for (auto item : ans) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
#endif