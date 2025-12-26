#include<vector>
#include<iostream>

using namespace std;

#define DEBUG 1

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for (int i : nums) {
            if (i == 0) {
                max = count > max ? count : max;
                count = 0;
            }
            else if (i == 1) {
                count++;
            }
        }
        max = count > max ? count : max;
        return max;
    }
};

#if DEBUG

int main(int argc, char const* argv[])
{
    Solution sol;

    vector<int> nums = { 1,1,0,0,1,1,1 };
    int ans = sol.findMaxConsecutiveOnes(nums);
    cout << ans << endl;

    return 0;
}

#endif