#include "declarations.hpp"

int main(void) {
    string user;
    double balance = loginBox(user); 

    unordered_map<string, pair<string, double>> users = loadUsers(customfile);

    int input, confirmation;
    do {
        menuDisplay(balance);        
        centerText("Select option: ", 22); cin >> input;
        confirmation = selectOption(input, users, user, balance);
    } while (confirmation == 0);

    gotoxy(35, 27); system("pause");
    return 0;
}