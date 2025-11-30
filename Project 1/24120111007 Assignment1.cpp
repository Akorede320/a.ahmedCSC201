#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    string Fullname;
    int JAMB;
    double WAEC;
    int age;
    int firstChoiceInput;
    int disciplinaryInput;
    int hostelPreference;
    double baseTuition = 1500000;
    double hostelFee = 0;
    double scholarshipPercent = 0;
    double meritGrant = 0;

    bool firstChoice;
    bool disciplinaryRecord;

    cout << "Enter your full name: ";
    getline(cin, Fullname);

    cout << "Enter your JAMB (0-400): ";
    cin >> JAMB;

    cout << "Enter your WAEC (0-100): ";
    cin >> WAEC;

    cout << "Enter your age (years): ";
    cin >> age;

    cout << "First choice PAU? (1 = Yes, 0 = No): ";
    cin >> firstChoiceInput;

    cout << "Any disciplinary record? (1 = Yes, 0 = No): ";
    cin >> disciplinaryInput;

    cout << "Hostel preference (1=Main, 2=Annex, 3=Day): ";
    cin >> hostelPreference;

    firstChoice = (firstChoiceInput == 1);
    disciplinaryRecord = (disciplinaryInput == 1);

    // Admission decision
    string admissionStatus;

    if (disciplinaryRecord == true || age < 15) {
        admissionStatus = "Rejected";
    }
    else if ((JAMB >= 220 && WAEC >= 60 && firstChoice == true) ||
             (JAMB >= 200 && WAEC >= 70)) {
        admissionStatus = "Admitted";
    }
    else {
        admissionStatus = "Pending";
    }

    // SCHOLARSHIP (only if admitted)
    if (admissionStatus == "Admitted") {
        if (JAMB >= 320) scholarshipPercent = 0.30;
        else if (JAMB >= 280) scholarshipPercent = 0.20;
        else if (JAMB >= 240) scholarshipPercent = 0.10;

        if (WAEC >= 80 && firstChoice == true) {
            scholarshipPercent += 0.05;
        }

        if (scholarshipPercent > 0.35) {
            scholarshipPercent = 0.35;
        }
    }

    // Hostel assignment
    string hostelName;

    if (admissionStatus == "Admitted" && disciplinaryRecord == false) {
        if (hostelPreference == 1) {
            hostelName = "Main Hostel";
            hostelFee = 180000;
        }
        else if (hostelPreference == 2) {
            hostelName = "Annex Hostel";
            hostelFee = 120000;
        }
        else if (hostelPreference == 3) {
            hostelName = "Day Student";
            hostelFee = 0;
        }
        else {
            hostelName = "Invalid Choice";
            hostelFee = 0;
        }
    }
    else if (admissionStatus == "Pending") {
        hostelName = "On Hold";
        hostelFee = 0;
    }
    else {
        hostelName = "Not Applicable";
        hostelFee = 0;
    }

    // Random Merit Grant
    srand(time(0));
    int r = rand() % 100 + 1;

    bool isPrime =
        (r==2 || r==3 || r==5 || r==7 || r==11 || r==13 || r==17 || r==19 ||
         r==23 || r==29 || r==31 || r==37 || r==41 || r==43 || r==47 ||
         r==53 || r==59 || r==61 || r==67 || r==71 || r==73 || r==79 ||
         r==83 || r==89 || r==97);

    if (isPrime && admissionStatus == "Admitted") {
        meritGrant = 50000;
    } else {
        meritGrant = 0;
    }

    double tuitionAfterScholarship = baseTuition - (scholarshipPercent * baseTuition);
    double totalPayable = tuitionAfterScholarship + hostelFee - meritGrant;

    if (totalPayable < 0) totalPayable = 0;

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "==========================" << endl;
    cout << "Name: " << Fullname << endl;
    cout << "Admission Status: " << admissionStatus << endl;

    cout << "Scholarship: " << (scholarshipPercent * 100)
         << "%  Tuition After Scholarship: ₦" << tuitionAfterScholarship << endl;

    cout << "Hostel: " << hostelName << "  Fee: ₦" << hostelFee << endl;

    cout << "Random draw: " << r << "   Merit Grant: ₦" << meritGrant << endl;

    cout << "TOTAL PAYABLE: ₦" << totalPayable << endl;
    cout << "==========================" << endl;

    return 0;
}
