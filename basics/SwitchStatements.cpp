#include <iostream>

using namespace std;

string getDayOfWeek(int dayNum) {
    string dayName;

    switch (dayNum) {
        case 0:
            dayName = "Monday";
            break;
        case 1:
            dayName = "Tuesday";
            break;
        case 2:
            dayName = "Wednesday";
            break;
        case 3:
            dayName = "Thursday";
            break;
        case 4:
            dayName = "Friday";
            break;
        case 5:
            dayName = "Saturday";
            break;
        case 6:
            dayName = "Sunday";
            break;
        default:
            dayName = "Invalid Day Number";
            break;
    }
    return dayName;
}

int main() {
    cout << getDayOfWeek(0) << endl;
    cout << getDayOfWeek(5) << endl;
    cout << getDayOfWeek(7) << endl;
    return 0;
}