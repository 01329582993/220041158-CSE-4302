#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class SavingsAccount
{
private:
    std::string accountName;
    std::string accountHolderName;
    std::string address;
    double annualInterestRate;
    double currentBalance;
    double minimumBalance;

public:
    SavingsAccount(std::string accName = "", std::string accHolderName = "", std::string addr = "",
                   double interestRate = 0, double balance = 0)
        : accountName(accName), accountHolderName(accHolderName), address(addr),
          annualInterestRate(interestRate), currentBalance(balance), minimumBalance(balance)
    {
    }

    std::string getAccountName() const
    {
        return accountName;
    }
    std::string getAccountHolderName() const
    {
        return accountHolderName;
    }
    std::string getAddress() const
    {
        return address;
    }
    double getAnnualInterestRate() const
    {
        return annualInterestRate;
    }
    double getCurrentBalance() const
    {
        return currentBalance;
    }


    void setAccountName(const std::string &accName)
    {
        accountName = accName;
    }
    void setAccountHolderName(const std::string &accHolderName)
    {
        accountHolderName = accHolderName;
    }
    void setAddress(const std::string &addr)
    {
        address = addr;
    }
    void setAnnualInterestRate(double interestRate)
    {
        annualInterestRate = interestRate;
    }
    void setCurrentBalance(double balance)
    {
        currentBalance = balance;
        if (balance < minimumBalance)
        {
            minimumBalance = balance;
        }
    }


    void deposit(double amount)
    {
        if (amount > 0)
        {
            currentBalance += amount;
        }
        else
        {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= currentBalance)
        {
            currentBalance -= amount;
            if (currentBalance < minimumBalance)
            {
                minimumBalance = currentBalance;
            }
        }
        else
        {
            cout << "Invalid withdrawal amount" << endl;
        }
    }


    double calculateInterest(int periodInMonths) const
    {
        double monthlyRate = (annualInterestRate / 100) / 12;
        return minimumBalance * monthlyRate * periodInMonths;
    }


    void disburseInterest(int periodInMonths)
    {
        double interest = calculateInterest(periodInMonths);
        deposit(interest);
        minimumBalance = currentBalance;
    }
};



void EditInformationByKeyboard(SavingsAccount &account)
{
    std::string accName, accHolderName, addr;
    double interestRate, balance;

    cout << "Account Name: ";
    std::getline(cin, accName);
    cout << "Account Holder Name: ";
    std::getline(cin, accHolderName);
    cout << "Address : ";
    std::getline(cin, addr);
    cout << "Annual Interest Rate : ";
    cin >> interestRate;
    cout << "Current Balance: ";
    cin >> balance;
    cin.ignore();

    account.setAccountName(accName);
    account.setAccountHolderName(accHolderName);
    account.setAddress(addr);
    account.setAnnualInterestRate(interestRate);
    account.setCurrentBalance(balance);
}


void generateInformationRandom(SavingsAccount &account)
{
    std::string accName = "Acc" + std::to_string(rand() % 100 + 1);
    std::string accHolderName = "Holder" + std::to_string(rand() % 100 + 1);
    std::string addr = "Addr " + std::to_string(rand() % 1000 + 1000);

    double interestRate = 2.0 + (rand() % 4) * 0.10;
    double balance = 1000.0 + rand() % 49000;

    account.setAccountName(accName);
    account.setAccountHolderName(accHolderName);
    account.setAddress(addr);
    account.setAnnualInterestRate(interestRate);
    account.setCurrentBalance(balance);
}


void ShowInterestAll(SavingsAccount accounts[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Account: " << accounts[i].getAccountName()
             << " Interest: " << accounts[i].calculateInterest(12) << endl;
    }
    char confirm;
    cout << "Disburse interest to all accounts? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
        for (int i = 0; i < size; i++)
        {
            accounts[i].disburseInterest(12);
        }
    }
}


bool compareByAccountName(const SavingsAccount &a, const SavingsAccount &b)
{
    return a.getAccountName() < b.getAccountName();
}


void ShowAllAlphabetically(SavingsAccount accounts[], int size)
{
    std::sort(accounts, accounts + size, compareByAccountName);

    for (int i = 0; i < size; i++)
    {
        cout << "Account: " << accounts[i].getAccountName()
             << " Balance: " << accounts[i].getCurrentBalance() << endl;
    }
}
