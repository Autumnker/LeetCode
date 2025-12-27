/**
 * 给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
 *  arr.length >= 3
 *  在 0 < i < arr.length - 1 条件下，存在 i 使得：
 *      arr[0] < arr[1] < ... arr[i-1] < arr[i]
 *      arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) { return false; }
        int count = 1;
        bool turn = true;
        bool up = false;
        bool down = false;

        for (int i = 1; i < n; ++i) {
            if (turn && arr[i - 1] < arr[i]) { up = true;count++;continue; }
            turn = false;
            if (!turn && arr[i - 1] > arr[i]) { down = true;count++;continue; }
        }

        return (count == n) && up && down;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> arr = { 9,8,7,6,5,4,3,2,1,0 };
    Solution sol;
    cout << sol.validMountainArray(arr) << endl;

    return 0;
}
