#ifndef COUNTER_H
#define COUNTER_H

#include<iostream>
#include <algorithm>

using namespace std;


class Counter {
private:
    int count;
    int incrementStep;

public:

    Counter(int step = 1) : count(0) {
        if (step > 0) {
            incrementStep = step;
        } else {
            incrementStep = 1;
        }
    }


    void setIncrementStep(int step_val) {
        if (count != 0) {
            cout << "Cannot set increment step when count is not zero" << endl;
        } else if (step_val > 0) {
            incrementStep = step_val;
        } else {
            cout << "Cannot set negative increment step, keeping previous value" << endl;
        }
    }

    int getCount() const {
        return count;
    }


    void increment() {
        count += incrementStep;
    }


    void resetCount(int step = 1) {
        count = 0;
        if (step > 0) {
            incrementStep = step;
        } else {
            incrementStep = 1;
        }
    }


    Counter operator+(const Counter& other) const {
        Counter result;
        if (this->incrementStep == other.incrementStep) {
            result.count = this->count + other.count;
            result.incrementStep = this->incrementStep;
        } else {
            cout << "Increment steps are not the same, operation not allowed" << endl;
        }
        return result;
    }


    bool operator>(const Counter& other) const {
        return this->count > other.count;
    }

    bool operator<(const Counter& other) const {
        return this->count < other.count;
    }

    bool operator>=(const Counter& other) const {
        return this->count >= other.count;
    }

    bool operator<=(const Counter& other) const {
        return this->count <= other.count;
    }

    bool operator==(const Counter& other) const {
        return this->count == other.count;
    }

    bool operator!=(const Counter& other) const {
        return this->count != other.count;
    }


    Counter& operator+=(const Counter& other) {
        this->count += other.count;
        this->incrementStep = max(this->incrementStep, other.incrementStep);
        return *this;
    }


    Counter operator++(int) {
        Counter temp = *this;
        this->increment();
        return temp;
    }


    Counter& operator++() {
        this->increment();
        return *this;
    }


    friend void testFunction(const Counter& c);
};


#endif // COUNTER_H
