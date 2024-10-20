#include "head.h"

int main() {
    SavingsAccount accounts[100];

    for (int i = 0; i < 2; i++) {
        cout << "Edit account information for account " << (i + 1) <<endl;
        EditInformationByKeyboard(accounts[i]);
    }



    for (int i = 2; i < 100; i++) {
        generateInformationRandom(accounts[i]);
    }


    ShowInterestAll(accounts, 100);


    ShowAllAlphabetically(accounts, 100);

    return 0;
}
