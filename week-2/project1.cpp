#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    string name, courseName, locationName;
    bool isPAU;
    int course, location, days = 0, r;
    double regFee = 0, lodgeFee = 0, lodgeCost, total, promo = 0;

    cout << "Name: "; getline(cin, name);
    cout << "PAU student? (1=Yes, 0=No): "; cin >> isPAU;
    cout << "Course (1–5): "; cin >> course;
    cout << "Location (1–5): "; cin >> location;

    // --- Course selection ---
    if (course == 1) { courseName = "Photography"; days = 3; regFee = 10000; }
    else if (course == 2) { courseName = "Painting"; days = 5; regFee = 8000; }
    else if (course == 3) { courseName = "Fish Farming"; days = 7; regFee = 15000; }
    else if (course == 4) { courseName = "Baking"; days = 5; regFee = 13000; }
    else if (course == 5) { courseName = "Public Speaking"; days = 2; regFee = 5000; }
    else return cout << "Invalid course.\n", 0;

    // --- Location selection ---
    if (location == 1) { locationName = "Camp House A"; lodgeFee = 10000; }
    else if (location == 2) { locationName = "Camp House B"; lodgeFee = 2500; }
    else if (location == 3) { locationName = "Camp House C"; lodgeFee = 5000; }
    else if (location == 4) { locationName = "Camp House D"; lodgeFee = 13000; }
    else if (location == 5) { locationName = "Camp House E"; lodgeFee = 5000; }
    else return cout << "Invalid location.\n", 0;

    lodgeCost = lodgeFee * days;

    // --- Discounts ---
    if (isPAU && (location == 1 || location == 2)) lodgeCost *= 0.95;   // 5% off lodging
    if (days > 5 || regFee > 12000) regFee *= 0.97;                     // 3% off registration

    // --- Random promo ---
    srand(time(0));
    r = rand() % 100 + 1;
    if (r == 7 || r == 77) promo = 500;

    total = regFee + lodgeCost - promo;

    // --- Output ---
    cout << fixed << setprecision(2);
    cout << "\n--- SUMMARY ---\n";
    cout << "Name: " << name << " (PAU: " << (isPAU ? "Yes" : "No") << ")\n";
    cout << "Course: " << courseName << "  Days: " << days << endl;
    cout << "Reg Fee: ₦" << regFee << "\nLodging: ₦" << lodgeFee 
         << " x " << days << " = ₦" << lodgeCost << "\n";
    cout << "Random: " << r << "  Promo: ₦" << promo << "\n";
    cout << "TOTAL: ₦" << total << endl;
}
