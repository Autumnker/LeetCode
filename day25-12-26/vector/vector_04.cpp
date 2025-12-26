#include<set>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

#define DEBUG 1

class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        set<int> st;
        int repeat = -1;
        int should = -1;
        int previous = 0;

        sort(nums.begin(), nums.end());
        for (int item : nums) st.insert(item);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == previous) {
                repeat = previous;
                break;
            }
            previous = nums[i];
        }

        for (int i = 1; i <= nums.size(); ++i) {
            if (st.find(i) == st.end()) {
                should = i;
                break;
            }
        }

        ans.push_back(repeat);
        ans.push_back(should);
        return ans;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        int n = nums.size();
        vector<int> count(n + 1);

        for (int num : nums) {
            ans[0] += num;
            if (count[num] == 0) {
                ans[1] += num;
                count[num]++;
            }
        }

        int sum = (n + 1) * n / 2;
        ans[0] = ans[0] - ans[1];
        ans[1] = sum - ans[1];

        return ans;
    }
};

#if DEBUG

int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> nums = { 2,2 };
    vector<int> ans = sol.findErrorNums(nums);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#endif