#include<iostream>
#include<vector>

using namespace std;

#define DEBUG 1

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= k) {
                ans += min(tickets[i], tickets[k]);
            }
            else {
                ans += min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> tickets = { 2,3,2 };
    int k = 2;
    cout << sol.timeRequiredToBuy(tickets, k);

    return 0;
}
#endif