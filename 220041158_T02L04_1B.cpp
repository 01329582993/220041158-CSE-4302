#include <iostream>

using namespace std;

class Airplan {
private :
    int Flight_number;
    string Destination ;
    float Distance;
    float MaxFuelCapacity;



    double CalFuel(){
        if(Distance <= 1000)
            return 500;
            else if (Distance > 1000 && Distance <= 2000)
                return 1100;
            else if (Distance > 2000)
                 return 2200;
                else return 10;
    }


public:


    void FeedInfo(){
        cin >> Flight_number;
        cin >> Destination;
        cin >>Distance;
        cin>> MaxFuelCapacity;
    }
    void ShowInfo(){

        cout << "Flight_number " << Flight_number<< endl;
        cout << "Destination "<< Destination << endl;
        cout << "Distance " << Distance << endl;
        cout << "MaxFuelCapacity "<<  MaxFuelCapacity<< endl;

        if(CalFuel() == 10)
            cout << "Not sufficient Fuel Capacity for this flight "<< endl;
            else
                cout << "Fuel capacity is fit for this flight distanc" << endl;
    }
};



int main(){
    Airplan Airbus;

    Airbus.FeedInfo();
    Airbus.ShowInfo();



    return 0;
}
