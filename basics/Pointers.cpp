#include <iostream>

using namespace std;

int main() {
    int age = 25;
    int *pAge = &age;
    double gpa = 3.5;
    double *pGpa = &gpa;
    string name = "Anna";
    string *pName = &name;

    cout << pAge << endl;
    cout << *pAge << endl;
    cout << pGpa << endl;
    cout << *pGpa << endl;
    cout << pName << endl;
    cout << *pName << endl;

    return 0;
}
