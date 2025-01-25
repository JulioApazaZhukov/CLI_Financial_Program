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
using std::cerr;
using std::out_of_range;
using std::invalid_argument;
using std::getline;

unordered_map<string, pair<string, double>> loadUsers(const string& customfile) 
{
    unordered_map<string, pair<string, double>> users;
    ifstream file(customfile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string user, password, balanceStr;

        if (getline(ss, user, ',') && getline(ss, password, ',') && getline(ss, balanceStr, ',')) {
            try {
                double balance = stod(balanceStr);
                users[user] = {password, balance};
            } catch (const invalid_argument&) {
                cerr << "Invalid balance for user: " << user << ". Skipping entry.\n";
                continue;
            } catch (const out_of_range&) {
                cerr << "Balance out of range for user: " << user << ". Skipping entry.\n";
                continue;
            }
        } else {
            cerr << "Malformed line in CSV: " << line << ". Skipping entry.\n";
        }
    }
    file.close();
    return users;
}

void appearance();
void gotoxy(int, int);

void registerUser(const string&, const string&, const string&);
bool authenticateUser(const unordered_map<string, pair<string, double>>&, const string&, const string&, double&);
double loginBox();

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