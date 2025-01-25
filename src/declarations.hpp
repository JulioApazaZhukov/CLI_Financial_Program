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
using std::pair;

unordered_map<string, pair<string, int>> loadUsers(const string& customfile) 
{
    unordered_map<string, pair<string, int>> users;
    ifstream file(customfile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user, password, balanceStr;
        getline(ss, user, ',');
        getline(ss, password, ',');
        getline(ss, balanceStr, ',');
        int balance = stoi(balanceStr);
        users[user] = {password, balance};
    }
    file.close();
    return users;
}

void appearance();
void gotoxy(int, int);

void registerUser(const string&, const string&, const string&);
bool autenticarUsuario(const unordered_map<string, string>&, const string&, const string&);
int loginBox();

void border(int, int, int, int);
void centerText(const char *, int);
void fundamentalInterfaceComponents();
void menuDisplay(double);
void calculatorMenuDisplay();
void dashboard(double);
int selectOption(int, double);

void launchCalculator(int);
void compoundInterest();
void simpleInterest();

#include "console_config.h"
#include "login.hpp"
#include "user_interface.h"
#include "financial_calculators.h"
#include "dashboard.h"