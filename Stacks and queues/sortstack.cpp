#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class SortedStack {
    public:
        stack<int> s;
        void sort();
};
    
    // Function to insert an element into the sorted stack
    void insertsorted(stack<int>& s, int topele) {
        if (s.empty() || s.top() <= topele) { // Fix: Corrected condition
            s.push(topele);
            return;
        }
    
        int popped = s.top();
        s.pop();
        
        insertsorted(s, topele);
        
        s.push(popped);
    }
    
    // Function to sort the stack recursively
    void SortedStack::sort() {
        if (s.empty()) return; // Base case
    
        int topele = s.top();
        s.pop();
    
        sort(); // Recursively sort the remaining stack
    
        insertsorted(s, topele); // Insert the element at its correct position
    }
    