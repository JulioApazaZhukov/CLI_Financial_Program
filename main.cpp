#include <iostream>
#include <stdlib.h>

#include "prototypes.h"
#include "console_config.h"
#include "user_interface.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    int input;
    do{
        system("cls");
        appearance();
        borderPrinting();
        staticText();
        
        centerText("Continue? ", 10); cin >> input;
    }while(input == 1);

    gotoxy(35, 27); system("pause");
    return 0;
}