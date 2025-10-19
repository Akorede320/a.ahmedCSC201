#include <iostream>
using namespace std;

int main() {
  double num1;
  cout << "Enter the first number :" ;
  cin >> num1;

  double num2;
  cout << "Enter the second number :" ;
  cin >> num2;

  double sum = num1 + num2 ;
  cout << "The sum is " << sum << endl ;
  double difference = num1 - num2;
  cout << "The difference is " << difference << endl ;
  double product = num1 * num2;
  cout << "The product is " << product << endl ;

  return 0;
  
}