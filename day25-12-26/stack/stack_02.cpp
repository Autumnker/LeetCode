#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<stdexcept>

using namespace std;

#define DEBUG 1

class Solution {
public:
    bool find_oper(const string& item) {
        for (string oper : _oper) {
            if (oper == item) { return true; }
        }
        return false;
    }

    int func(const int& a, const int& b, const string& oper) {
        if (oper == "+") {
            return a + b;
        }
        else if (oper == "-") {
            return a - b;
        }
        else if (oper == "*") {
            return a * b;
        }
        else if (oper == "/") {
            return a / b;
        }
        else {
            throw invalid_argument("Invalid operator: " + oper);
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int ans;
        for (string item : tokens) {
            // 判断是否为运算符
            if (find_oper(item)) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                try {
                    ans = func(a, b, item);
                }
                catch (const invalid_argument& e) {
                    cerr << e.what() << endl;
                }
                nums.push(ans);
            }
            else {  // 如果是数字,转换成整数并压入栈中
                int num = stoi(item);
                nums.push(num);
            }
        }
        ans = nums.top();
        return ans;
    }
private:
    vector<string> _oper = { "+","-","*","/" };
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;
    vector<string> target = { "2","1","+","3","*" };

    int ans = sol.evalRPN(target);
    cout << ans << endl;

    return 0;
}
#endif
