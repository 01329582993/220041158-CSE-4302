#include <iostream>
using namespace std;

class Calculator {
private:
    int currentStatus;

    int getStatus() {
        return currentStatus;
    }

    void setStatus(int status) {
        currentStatus = status;
    }

public:

    Calculator() {
        currentStatus = 0;
    }

    Calculator(int status) {
        currentStatus = status;
    }


    ~Calculator() {
        cout << "Display : " << currentStatus << endl;
        cout << "Destructor of the Calculator object is called " << endl;
    }


    void add(int value) {
        setStatus(getStatus() + value);
    }


    void subtract(int value) {
        setStatus(getStatus() - value);
    }


    void multiply(int value) {
        setStatus(getStatus() * value);
    }


    int divideBy(int value) {
        if (value == 0) {
            cout << "Invalid operation " << endl;
            return 1;
        }
        int remainder = getStatus() % value;
        setStatus(getStatus() / value);
        return remainder;
    }

    void clear() {
        setStatus(0);
    }


    void display() {
        cout << "Display: " << getStatus() << endl;
    }
};

int main() {
    Calculator cal;

    cal.add(10);
    cal.getstatus();

    cal.add(7);
    cal.display();

    cal.multiply(31);
    cal.display();


    return 0;
}
