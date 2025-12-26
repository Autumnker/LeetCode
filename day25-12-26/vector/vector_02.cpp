#include<vector>
#include<iostream>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (i < n) {
                ans[2 * i] = nums[i];
            }
            else {
                ans[2 * (i - n) + 1] = nums[i];
            }
        }
        return ans;
    }
};

#if DEBUG

int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> nums = { 1,2,3,4,5,6 };
    vector<int> ans = sol.shuffle(nums, 3);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#endif