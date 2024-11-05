#include <iostream>
using namespace std;


void fibo(int n) {
  
    int fib = 0;
    int fib1 = 1;
    int fib2;

    cout << fib << " ";
     cout << fib1 << " "; 
    int i=2;

    while(i<n){
        fib2 = fib + fib1; 
        cout << fib2 << " "; 
        fib = fib1; 
        fib1 = fib2;
        i++;
    }
    
}


int fibonacci(int n) {
    if (n <= 1) return n; 
    return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Non-recursive Fibonacci series: ";
    fibo(n); 

    cout << "\nRecursive Fibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " "; 
    }
    cout << endl;

    return 0;
}
