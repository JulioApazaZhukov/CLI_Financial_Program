#include "prototypes.h"

int main (void)
{
    loginBox();

    int input, confirmation;
    do{
        menuDisplay();        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input);
    }while(confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}