#include "head.h"

using namespace std;


int main()
{
    Employee emp1, emp2;

    cout << "Enter information for Employee 1:\n";
    emp1.setInfo();

    cout << "\nEnter information for Employee 2:\n";
    emp2.setInfo();

    cout << "\nInformation of Employee 1:\n";
    emp1.getInfo();

    cout << "\nInformation of Employee 2:\n";
    emp2.getInfo();

    cout << "\nComparing ages of Employee 1 and Employee 2:\n";
    const Employee elder = emp1.compareAge(emp2);
    cout << "The elder employee is:\n";
    elder.getInfo();

    return 0;
}
