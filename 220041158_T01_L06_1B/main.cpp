#include"Counter.h"


using namespace std;


//
//void test(const Counter& c) {
//    cout << c.getCount() << endl;
//}

int main() {
    Counter c1, c2(3), c3(3);

    c1.setIncrementStep(5);
    c2.increment();
    c2.increment();

    c2.setIncrementStep(2);

    c1 = c2 + c3;

    //test(c1);

    c1++;
    ++c2;

    if (c1 > c2) {
        cout << "c1 is greater than c2" << endl;
    }

    return 0;
}
