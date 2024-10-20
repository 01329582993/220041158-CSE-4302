#include <iostream>

using namespace std;

class BankAccount{
private:

    int account_number;
    string account_holder_name;
    string account_type;
    double current_balance;

public:
    BankAccount(int minimum_balance, int Account_number, string Account_holder_name, string Account_type) {

            current_balance = minimum_balance;
            account_number = Account_number;
            account_holder_name = Account_holder_name;
            account_type = Account_type;

    }

    ~BankAccount(){
        cout << "Account of "<<account_holder_name<< "account no " <<account_number ;
        cout << "is destroyed with a balance BDT " << current_balance<< endl;


    }

   void  FeedInfo(){
       cin>> account_number;
       cin>> account_holder_name;
       cin>> account_type;
       cin>> current_balance;
    }

    void show_all(){
        cout <<account_number;
       cout <<  account_holder_name;
       cout<<  account_type;
    }

    void showBalance(){
    cout << "Current Balance "<< current_balance<< endl;
    }

    void deposit(int amount){
    current_balance += amount;
    }

    void withdrawal(int amount){
    current_balance -= amount;
    }

    void giveInterst(){
    current_balance += 0.03* current_balance;
    }


};

int main(){
    void display_stat(){

    }



return 0;
}
