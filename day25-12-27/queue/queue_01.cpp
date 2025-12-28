#include<iostream>
#include<vector>

using namespace std;

#define DEBUG 0

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int sum0 = 0;
        int sum1 = 0;
        for (int i = 0; i < n; ++i) {
            if (students[i] == 0) { sum0++; }
            else if (students[i] == 1) { sum1++; }
        }

        for (int i = 0; i < sandwiches.size(); ++i) {
            if (sandwiches[i] == 0 && sum0 > 1) { sum0--; }
            else if (sandwiches[i] == 1 && sum1 > 0) { sum1--; }
            else { break; }
        }

        return sum0 + sum1;
    }
};

#if DEBUG
int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> students = { 1,1,0,0 };
    vector<int> sandwiches = { 0,1,0,1 };
    cout << sol.countStudents(students, sandwiches);

    return 0;
}
#endif