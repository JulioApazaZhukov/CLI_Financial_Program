#include "prototypes.h"

using std::cin;
using std::cout;
using std::endl;

int main (void)
{
    int input, confirmation;
    do{
        menuDisplay();        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input);
    }while(confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}