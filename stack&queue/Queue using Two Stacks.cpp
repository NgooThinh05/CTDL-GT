#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


class QueueUsingStacks {
private:
    stack<int> stack_enqueue;
    stack<int> stack_dequeue;

public:
    void enqueue(int value) {
        stack_enqueue.push(value);
    }

    void dequeue() {
        if (stack_dequeue.empty()) {
            while (!stack_enqueue.empty()) {
                stack_dequeue.push(stack_enqueue.top());
                stack_enqueue.pop();
            }
        }
        if (!stack_dequeue.empty()) {
            stack_dequeue.pop();
        }
    }

    int front() {
        if (stack_dequeue.empty()) {
            while (!stack_enqueue.empty()) {
                stack_dequeue.push(stack_enqueue.top());
                stack_enqueue.pop();
            }
        }
        return stack_dequeue.empty() ? -1 : stack_dequeue.top();  // Return -1 if the queue is empty
    }
};

int main() {
    int q;
    cin >> q;
    QueueUsingStacks queue;

    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int value;
            cin >> value;
            queue.enqueue(value);
        } else if (query_type == 2) {
            queue.dequeue();
        } else if (query_type == 3) {
            cout << queue.front() << endl;
        }
    }

    return 0;
}
