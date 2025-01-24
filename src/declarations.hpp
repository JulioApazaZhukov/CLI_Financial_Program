#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::unordered_map;
using std::ios;
using std::ifstream;
using std::stringstream;

unordered_map<string, string> loadUsers(const string& customfile) 
{
    unordered_map<string, string> users;
    ifstream file(customfile);
    string linea, user, password;

    while (getline(file, linea)) {
        stringstream ss(linea);
        getline(ss, user, ',');
        getline(ss, password, ',');
        users[user] = password;
    }

    file.close();
    return users;
}

void appearance();
void gotoxy(int, int);

void registerUser(const string&, const string&, const string&);
bool autenticarUsuario(const unordered_map<string, string>&, const string&, const string&);
void loginBox();

void border(int, int, int, int);
void centerText(const char *, int);
void fundamentalInterfaceComponents();
void menuDisplay();
void calculatorMenuDisplay();
void dashboard(float);
int selectOption(int);

void launchCalculator(int);
void compoundInterest();
void simpleInterest();

#include "console_config.h"
#include "login.hpp"
#include "user_interface.h"
#include "financial_calculators.h"
#include "dashboard.h"