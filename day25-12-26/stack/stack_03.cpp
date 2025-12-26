#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<stdexcept>

using namespace std;

#define DEBUG 1

class Solution2 {
public:
    vector<string> split(const string& str, const char& delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        vector<vector<string>> tokens;
        stack<vector<string>> stk;

        for (string item : logs) {
            tokens.emplace_back(split(item, ':'));
        }

        for (auto token : tokens) {
            if (token[1] == "start") {
                if (!stk.empty()) {
                    auto top = stk.top();
                    ans[stoi(top[0])] += stoi(token[2]) - stoi(top[2]);
                }
                stk.push(token);
            }
            else {
                auto top = stk.top();
                stk.pop();
                ans[stoi(top[0])] += stoi(token[2]) - stoi(top[2]) + 1;
                if (!stk.empty()) {
                    int startTime = stoi(stk.top()[2]);
                    startTime = stoi(token[2]) + 1; // 下一个函数的end时间 - 当前函数的end时间 = 在该时间区间内实际占有时间 + 1
                    stk.top()[2] = to_string(startTime);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> ids;

        int pre_startTime = 0;
        for (string log : logs) {
            vector<string> tokens;
            string token;
            stringstream ss(log);
            while (getline(ss, token, ':')) { tokens.push_back(token); }

            string type = tokens[1];
            int id = stoi(tokens[0]);
            int currTime = stoi(tokens[2]);

            if (type == "start") {
                if (!ids.empty()) {
                    ans[ids.top()] += currTime - pre_startTime;
                }
                ids.push(id);
                pre_startTime = currTime;
            }
            else {
                ids.pop();
                ans[id] += currTime - pre_startTime + 1;
                pre_startTime = currTime + 1;
            }
        }

        return ans;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;
    vector<string> target = { "0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8" };
    int n = 2;
    vector<int> ans = sol.exclusiveTime(n, target);
    for (auto item : ans) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
#endif
