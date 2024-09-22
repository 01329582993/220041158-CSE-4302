#include <iostream>
#include <string>
#include <cmath>

class Temperature
{
private:
    double value;
    std::string unit;


    bool isValidUnit(const std::string &u)
    {
        return (u == "Celsius" || u == "Fahrenheit" || u == "Kelvin");
    }

    bool isAboveAbsoluteZero(double val, const std::string &u)
    {
        if (u == "Celsius" && val >= -273.15) return true;
        if (u == "Fahrenheit" && val >= -459.67) return true;
        if (u == "Kelvin" && val >= 0) return true;
        return false;
    }

public:

    Temperature() : value(0), unit("Celsius") {}

    void assign(double temp, const std::string &u)
    {
        if (!isValidUnit(u))
        {
            std::cout << "Error: Invalid unit! Use 'Celsius', 'Fahrenheit', or 'Kelvin'.\n";
            return;
        }
        if (!isAboveAbsoluteZero(temp, u))
        {
            std::cout << "Error: Temperature cannot be lower than absolute zero!\n";
            return;
        }
        value = temp;
        unit = u;
    }

    double convert(const std::string &targetUnit)
    {
        if (!isValidUnit(targetUnit))
        {
            std::cout << "Error: Invalid target unit! Use 'Celsius', 'Fahrenheit', or 'Kelvin'.\n";
            return NAN;
        }

        double tempInCelsius;


        if (unit == "Celsius")
        {
            tempInCelsius = value;
        }
        else if (unit == "Fahrenheit")
        {
            tempInCelsius = (value - 32) * 5.0 / 9.0;
        }
        else if (unit == "Kelvin")
        {
            tempInCelsius = value - 273.15;
        }

        if (targetUnit == "Celsius")
        {
            return tempInCelsius;
        }
        else if (targetUnit == "Fahrenheit")
        {
            return tempInCelsius * 9.0 / 5.0 + 32;
        }
        else if (targetUnit == "Kelvin")
        {
            return tempInCelsius + 273.15;
        }

        return NAN;
    }

    void print() const
    {
        std::cout << "The temperature is " << value << " " << unit << ".\n";
    }
};

int main()
{
    Temperature temp;

    temp.assign(100, "Celsius");
    temp.print();


    std::cout << "Converted to Fahrenheit: " << temp.convert("Fahrenheit") << " Fahrenheit.\n";
    std::cout << "Converted to Kelvin: " << temp.convert("Kelvin") << " Kelvin.\n";

    temp.assign(-500, "Celsius");
    temp.assign(50, "Rankine");

    return 0;
}
