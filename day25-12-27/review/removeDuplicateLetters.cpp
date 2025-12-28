/**
 * Q1. 去除重复字母
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
 * 需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 */

#include<vector>
#include<string>
#include<stack>
#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

/**
 * 1. 单调递增栈
 * 2. 记录每个字符最后出现的位置
 * 3. 记录该字符是否已经存在于栈中
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> map;
        unordered_set<char> set;
        stack<char> stk;
        int n = s.length();

        for (int i = 0; i < n; ++i) {   // 记录每个字符最后出现的位置
            map[s[i]] = i;
        }

        for (int i = 0; i < n; ++i) {   // 弹出栈顶前,需要确认后面还有栈顶元素,且待入栈元素在栈中并不存在
            while (!stk.empty() && map[stk.top()] > i && stk.top() > s[i] && set.count(s[i]) == 0) {
                set.erase(stk.top());
                stk.pop();
            }
            if (set.count(s[i]) == 0) {
                stk.push(s[i]);
                set.insert(s[i]);
            }
        }

        string ans;
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    string s = "cbacdcbc";
    string ans = sol.removeDuplicateLetters(s);
    cout << ans << endl;

    return 0;
}
