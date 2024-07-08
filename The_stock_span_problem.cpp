#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s;

    // Initialize the span of the first day
    span[0] = 1;
    s.push(0);

    // Calculate span for rest of the days
    for (int i = 1; i < n; i++) {
        // Pop elements from the stack while the stack is not empty and the
        // price at the top of the stack is less than or equal to the current price
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        // If stack becomes empty, then price[i] is greater than all elements
        // on left of it, so span[i] is i+1. Otherwise, price[i] is greater than
        // elements after the top of the stack
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());

        // Push this element to the stack
        s.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};  // Example input
    vector<int> span = calculateSpan(prices);

    cout << "Span values for the given prices are: ";
    for (int s : span) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
