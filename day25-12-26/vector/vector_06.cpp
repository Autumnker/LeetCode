#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> count(n + 1);

        for (int num : nums) {
            count[num]++;
        }

        for (int i = 1; i < n + 1; ++i) {
            if (count[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

#if DEBUG

int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    vector<int> ans = sol.findDisappearedNumbers(nums);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#endif