// For example, a number represented as abcd can be written as follows:

// abcd = a*10^3 + b*10^2 + c*10^1 + d*10^0   

// We can separate the digits and rewrite this as:
// abcd = a + b + c + d + (a*999 + b*99 + c*9)
// abcd = a + b + c + d + 9*(a*111 + b*11 + c)

// This implies that any number can be expressed as the sum of its digits plus a multiple of 9.
// So, if we take modulo with 9 on each side, 
// abcd % 9 = (a + b + c + d) % 9 + 0


// This means that the remainder when abcd is divided by 9 is equal to the remainder where the sum of its digits (a + b + c + d) is divided by 9.
// C++ program to find the digit sum 
// using mathematical formula

#include <iostream>
using namespace std;

int singleDigit(int n) {
  
      // If given number is zero its
      // digit sum will be zero only
    if (n == 0) 
       return 0;
    
      // If result of modulo operation is 
      // zero then, the digit sum is 9
      if(n % 9 == 0)
          return 9;
     
      return (n % 9);
}

int main() {
    int n = 1234;
    cout << singleDigit(n);
    return 0;
}


