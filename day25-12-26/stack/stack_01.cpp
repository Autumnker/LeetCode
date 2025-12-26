#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        int max = target.size();
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (target[index] == i) {
                ans.push_back("Push");
                index++;
                if(index == max) break;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> target = { 1,3 };
    int n = 3;

    vector<string> ans = sol.buildArray(target, n);
    for(auto item : ans){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
#endif
