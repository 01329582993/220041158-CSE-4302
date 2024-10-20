#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <cmath>    // for sqrt and pow
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;

class Coordinate {
private:
    float abscissa;
    float ordinate;

public:
    // Constructors
    Coordinate() : abscissa(0), ordinate(0) {} // Non-argumented constructor

    Coordinate(float x, float y) : abscissa(x), ordinate(y) {} // Argumented constructor

    // Destructor
    ~Coordinate() {}

    // Display function to print abscissa and ordinate
    void display() const {
        cout << "Coordinate: (" << abscissa << ", " << ordinate << ")" << endl;
    }

    // Operator overloading to calculate the distance between two points
    float operator-(Coordinate c) const {
        return sqrt(pow(c.abscissa - this->abscissa, 2) + pow(c.ordinate - this->ordinate, 2));
    }

    // Function to get the distance from the origin (0,0)
    float getDistance() const {
        return sqrt(pow(abscissa, 2) + pow(ordinate, 2));
    }

    // Function to move the abscissa by val
    void move_x(float val) {
        abscissa += val;
    }

    // Function to move the ordinate by val
    void move_y(float val) {
        ordinate += val;
    }

    // Function to move both abscissa and ordinate by x_val and y_val
    void move(float x_val, float y_val) {
        abscissa += x_val;
        ordinate += y_val;
    }

    // Operator overloading for comparison based on distance from the origin
    bool operator>(const Coordinate& c) const {
        return this->getDistance() > c.getDistance();
    }

    bool operator<(const Coordinate& c) const {
        return this->getDistance() < c.getDistance();
    }

    bool operator>=(const Coordinate& c) const {
        return this->getDistance() >= c.getDistance();
    }

    bool operator<=(const Coordinate& c) const {
        return this->getDistance() <= c.getDistance();
    }

    bool operator==(const Coordinate& c) const {
        return this->abscissa == c.abscissa && this->ordinate == c.ordinate;
    }

    bool operator!=(const Coordinate& c) const {
        return !(*this == c);
    }

    // Friend function to display coordinates
    friend void displayCoordinate(const Coordinate& c);
};

// Random assignment function
void randomAssignment(Coordinate c[], int size) {
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < size; i++) {
        float x = static_cast<float>(rand() % 201 - 100); // Random value between -100 and 100
        float y = static_cast<float>(rand() % 201 - 100); // Random value between -100 and 100
        c[i] = Coordinate(x, y);  /
    }
}


void sort(Coordinate c[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (c[j] > c[j + 1]) {

                Coordinate temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}


#endif // COORDINATE_H
