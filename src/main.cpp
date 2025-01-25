#include "declarations.hpp"

int main (void)
{
    double balance = loginBox();
    // The function loginBox() return the balance from the user account

    int input, confirmation;
    do{
        menuDisplay(balance);        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input, balance);
    }while(confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}