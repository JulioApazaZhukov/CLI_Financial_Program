#include "prototypes.h"
#include "console_config.h"
#include "user_interface.h"
#include "financial_calculators.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    int input, confirmation;
    do{
        loadHomeScreen();        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input);
    }while(confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}