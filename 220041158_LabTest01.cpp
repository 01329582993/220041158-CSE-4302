#include<iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;


class Flower
{
private :

    std::string name;
    double price ;
    bool hasScent;
public:
    Flower(std::string n, double p, bool h)
    {
        name = n;
        price = p;
        hasScent = h;
    }

    Flower()
    {
        name = "Rose";
        price = 100;
        hasScent = true;
    }
    std::string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    bool gethasScent()
    {
        return hasScent;
    }
    bool operator>(const Flower& flower) const
    {
        return this->price > flower.price;
    }

    bool operator<(const Flower& flower) const
    {
        return this->price < flower.price;
    }
    bool operator==(const Flower& flower) const
    {
        return this->price == flower.price;
    }


    void display ()
    {
        cout<< name<< endl;
        cout<< price << endl;
        cout << hasScent<< endl;


    }



};
//Flower flower;
vector<Flower> flower;


void Sort()
{
    auto first = flower.begin();
    auto last  = flower.end();
    std::sort(last, first);
}

int main()
{
    for(auto i: flower[10])
    {
        cout<<flower<< endl;
    }










}
