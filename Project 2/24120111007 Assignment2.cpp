#include <iostream>
using namespace std;

bool verifyPin(int correctPin) {
    int enteredPin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == correctPin) {
            return true; 
        } else {
            cout << "Incorrect PIN. Try again." << endl;
        }

        attempts++;
    }

    return false; 
}

// Display the ATM menu
void displayMenu() {
    cout << "======== ATM MENU ========" << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Deposit Cash" << endl;
    cout << "3. Withdraw Cash" << endl;
    cout << "4. Reset PIN" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// View balance
double viewBalance(double balance) {
    cout << "Your current balance is: ₦" << balance << endl;
    return balance;
}

// Deposit money
double depositMoney(double balance) {
    double deposit;
    cout << "Enter amount to deposit: ₦";
    cin >> deposit;

    if (deposit > 0) {
        balance += deposit;
        cout << "Deposit successful. New balance: ₦" << balance << endl;
    } else {
        cout << "Invalid amount. Deposit failed." << endl;
    }

    return balance;
}

//  Withdraw money
double withdrawMoney(double balance, double dailyLimit) {
    double withdraw;
    cout << "Enter amount to withdraw: ₦";
    cin >> withdraw;

    if (withdraw > balance) {
        cout << "Insufficient balance." << endl;
    } else if (withdraw > dailyLimit) {
        cout << "Amount exceeds daily withdrawal limit of ₦" << dailyLimit << endl;
    } else if (withdraw <= 0) {
        cout << "Invalid amount. Withdrawal failed." << endl;
    } else {
        balance -= withdraw;
        cout << "Withdrawal successful. New balance: ₦" << balance << endl;
    }

    return balance;
}

// Reset PIN
int resetPin(int currentPin) {
    int oldPin, newPin;
    cout << "Enter your old PIN: ";
    cin >> oldPin;

    if (oldPin == currentPin) {
        cout << "Enter your new PIN: ";
        cin >> newPin;
        cout << "PIN successfully changed." << endl;
        return newPin;
    } else {
        cout << "Incorrect old PIN. PIN not changed." << endl;
        return currentPin; 
    }
}

int main() {
    double balance = 50000;      
    double dailyLimit = 20000;   
    int pin = 4321;              
    int choice;

    
    if (!verifyPin(pin)) {
        cout << "Account Locked. Please contact your bank." << endl;
        return 0; 
    }


    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                balance = viewBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance, dailyLimit);
                break;
            case 4:
                pin = resetPin(pin);
                break;
            case 5:
                cout << "Thank you for using our ATM." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl; 
    } while (choice != 5);

    return 0;
}

