/**
 * 单调栈 Q3 "柱状图中最大的矩形"
 * ⭐⭐⭐⭐⭐
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

#define DEBUG 1

// 暴力解法
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int count = 1;  // 当前矩形本身算在内
            int minHeight = heights[i];

            // 向左扩散
            for (int ll = i - 1; ll >= 0; --ll) {
                if (heights[ll] < minHeight) { break; }
                count++;
            }
            // 向右扩散
            for (int rr = i + 1; rr < n; ++rr) {
                if (heights[rr] < minHeight) { break; }
                count++;
            }

            ans = count * minHeight > ans ? count * minHeight : ans;
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> stk;
        vector<int>left(n), right(n);
        for (int i = 0; i < n; ++i) {   // 先找到左边第一个高度小于自身的矩形的索引
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {   // 再找到右边第一个高度小于自身的矩形的索引
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        // 计算面积
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };
    int ans = sol.largestRectangleArea(heights);
    cout << ans << endl;

    return 0;
}
#endif