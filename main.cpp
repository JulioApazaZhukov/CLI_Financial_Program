#include <iostream>
#include <stdlib.h>

#include "console_config.h"
#include "user_interface.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    appearance();
    borderPrinting();
    staticText();

    gotoxy(35, 27); system("pause");
    return 0;
}