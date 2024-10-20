#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>
#include <string>

#include <iostream>
#include <string>
#include <ctime>

struct Date
{
    int day;
    int month;
    int year;


    void printDate() const
    {
        std::cout << day << "/" << month << "/" << year;
    }


};

class Employee
{
private:
    std::string name;
    Date dateOfBirth;
    float salary;

public:

    Employee() : name("John Doe"), dateOfBirth{1, 1, 2002}, salary(10000) {}


    const std::string& getName() const
    {
        return name;
    }

    void setName(const std::string& name)
    {
        if (name.length() > 2)
        {
            this->name = name;
        }
        else
        {
            this->name = "John Doe";
        }
    }

    const Date& getDateOfBirth() const
    {
        return dateOfBirth;
    }

    void setDateOfBirth(const Date& dob)
    {
        if ((2024 -dob.year) >18 )
        {
            dateOfBirth = dob;
        }
        else
        {
            dateOfBirth = {1, 1, 2002};
        }
    }


    float getSalary() const
    {
        return salary;
    }

    void setSalary(float salary)
    {
        if (salary >= 10000 && salary <= 100000)
        {
            this->salary = salary;
        }
        else
        {
            this->salary = 10000;
        }
    }


    void setInfo()
    {
        std::string nameInput;
        Date dobInput;
        float salaryInput;

        std::cout << "Enter Name: ";
        std::getline(std::cin, nameInput);
        setName(nameInput);

        std::cout << "Enter Date of Birth (day month year): ";
        std::cin >> dobInput.day >> dobInput.month >> dobInput.year;
        setDateOfBirth(dobInput);

        std::cout << "Enter Salary: ";
        std::cin >> salaryInput;
        setSalary(salaryInput);

        std::cin.ignore();
    }


    void getInfo() const
    {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Date of Birth: ";
        dateOfBirth.printDate();
        std::cout << std::endl;
        std::cout << "Salary: BDT " << getSalary() << std::endl;
    }


    const Employee compareAge(const Employee& e) const
    {
        if (dateOfBirth.year < e.dateOfBirth.year)
        {
            return *this;
        }
        else if (dateOfBirth.year == e.dateOfBirth.year)
        {
            if (dateOfBirth.month < e.dateOfBirth.month)
            {
                return *this;
            }
            else if (dateOfBirth.month == e.dateOfBirth.month)
            {
                return (dateOfBirth.day <= e.dateOfBirth.day) ? *this : e;
            }
            else
            {
                return e;
            }
        }
        else
        {
            return e;
        }
    }
};




#endif
