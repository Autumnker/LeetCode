#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pairs;
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            pairs.emplace_back(make_pair(nums[i], i));
        }

        // sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        //     return a.first < b.first;
        //     });
        sort(pairs.begin(), pairs.end());

        int previous_key = INT_MIN;
        int previous_val = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (pairs[i].first == previous_key) {
                ans[pairs[i].second] = previous_val;
                continue;
            }
            ans[pairs[i].second] = i;
            previous_key = pairs[i].first;
            previous_val = i;
        }

        return ans;
    }
};

#if DEBUG

int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> nums = { 8,1,2,2,3 };
    vector<int> ans = sol.smallerNumbersThanCurrent(nums);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#endif