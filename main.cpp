#include "prototypes.h"
#include "console_config.h"
#include "user_interface.h"
#include "compound_interest.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    int input;
    do{
        loadHomeScreen();        
        centerText("Select option: ", 25); cin >> input;
        selectOption(input);
    }while(input == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}