#include <iostream>
#include <stdexcept>
using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            throw overflow_error("Stack1 Overflow");
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            throw overflow_error("Stack2 Overflow");
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            throw underflow_error("Stack1 Underflow");
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            throw underflow_error("Stack2 Underflow");
        }
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == size;
    }
};

int main() {
    TwoStacks ts(10);
    
    // Operations on Stack1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);
    
    cout << "Popped element from Stack1 is: " << ts.pop1() << endl;
    
    // Operations on Stack2
    ts.push2(11);
    ts.push2(22);
    ts.push2(33);
    
    cout << "Popped element from Stack2 is: " << ts.pop2() << endl;
    
    return 0;
}
