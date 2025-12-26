#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2 * nums.size());
        for(int i = 0; i < nums.size(); ++i){
            ans[i] = nums[i];
            ans[nums.size() + i] = nums[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums = {1,2,3,4,5};
    vector<int> ans = sol.getConcatenation(nums);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
