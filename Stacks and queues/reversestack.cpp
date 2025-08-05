#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert at bottom of stack
void insertAtBottom(stack<int>& st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topElem);
}

// Recursive function to reverse stack
void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int topElem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElem);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    reverseStack(st);

    cout << "\nReversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
