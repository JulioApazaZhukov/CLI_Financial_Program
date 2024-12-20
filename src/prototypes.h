#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void appearance();
void gotoxy(int, int);
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