#include <iostream>
#include <stdlib.h>
#include <Windows.h>

void appearance();
void gotoxy(int, int);
void border(int, int, int, int);
void centerText(const char *, int);
void fundamentalInterfaceComponents();
void menuDisplay();
void calculatorMenuDisplay();
void dashboard();
int selectOption(int);

void launchCalculator(int);
void compoundInterest();
void simpleInterest();

#include "console_config.h"
#include "user_interface.h"
#include "financial_calculators.h"
#include "dashboard.h"