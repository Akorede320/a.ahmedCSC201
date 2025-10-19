#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter the first number: ";
    cin >> a;

    int b;
    cout << "Enter the second number: ";
    cin >> b;

    int temp;

    cout << "\nBefore swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
