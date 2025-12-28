/**
 * 给定一个表示 大整数 的整数数组 digits，其中 digits[i] 是整数的第 i 位数字。这些数字按从左到右，从最高位到最低位排列。
 * 这个大整数不包含任何前导 0。
 * 将大整数加 1，并返回结果的数字数组。
 */

#include<vector>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        stack<int> tmp;
        bool carry = true;

        for (int i = n - 1; i >= 0; --i) {
            if (carry) {
                if (digits[i] + 1 > 9) {
                    digits[i] = 0;
                }
                else {
                    digits[i] += 1;
                    carry = false;
                }
            }
            tmp.push(digits[i]);
        }

        if (carry) {
            tmp.push(1);
        }

        while (!tmp.empty()) {
            ans.push_back(tmp.top());
            tmp.pop();
        }

        return ans;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> digits = { 4,3,2,1 };
    Solution sol;
    vector<int> ans = sol.plusOne(digits);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
