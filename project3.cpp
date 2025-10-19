#include <iostream>
using namespace std;

int main() {
  double purchaseAmount, salesTax, totalAmount;

    cout << "Enter the total purchase amount: ";
    cin >> purchaseAmount;

    // Calculate 6% sales tax
    salesTax = 0.06 * purchaseAmount;

    // Calculate total with tax
    totalAmount = purchaseAmount + salesTax;

    cout << "\nSales tax (6%) = " << salesTax << endl;
    cout << "Total amount including tax = " << totalAmount << endl;

    return 0;
}