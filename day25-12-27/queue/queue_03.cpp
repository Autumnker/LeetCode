#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define DEBUG 1

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ans = stk2.top();
        stk2.pop();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ans;
    }

    int peek() {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ans = stk2.top();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ans;
    }

    bool empty() {
        return stk1.empty();
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#if DEBUG
int main(int argc, char const* argv[])
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->peek();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();

    cout << param_2 << " " << param_3 << " " << param_4 << endl;

    return 0;
}
#endif