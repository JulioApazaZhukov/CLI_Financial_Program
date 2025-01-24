#include "declarations.hpp"

int main (void)
{
    loginBox();
    // The function loginBox() will return the balance from the user account

    int input, confirmation;
    do{
        menuDisplay();        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input);
    }while(confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}