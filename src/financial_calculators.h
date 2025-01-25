void launchCalculator (int input)
{
    switch (input){
    case 1:
        compoundInterest();
        break;
    case 2:
        simpleInterest();    
    default:
        break;
    }
}

void compoundInterest (void)
{
    system("cls");
    fundamentalInterfaceComponents();

    float principal, interestRate;
    int numberOfCapitalizationPeriods;

    gotoxy(30,10); printf("Enter the Principal: "); scanf("%f", &principal);
    gotoxy(30,12); printf("Enter the interest rate: "); scanf("%f", &interestRate);
    gotoxy(30,14); printf("Enter the number of capitalization periods: "); scanf("%i", &numberOfCapitalizationPeriods);

    numberOfCapitalizationPeriods--;
    float coefficient = (1 + interestRate/100);

    float multiplier = coefficient;
    while(numberOfCapitalizationPeriods > 0){
        multiplier *= coefficient;
        numberOfCapitalizationPeriods--;
    }

    float newPrincipal = principal * multiplier;
    float netEarnings = newPrincipal - principal;

    gotoxy(30,16); printf("New principal: %.2f", newPrincipal);
    gotoxy(30,18); printf("Net interes earning: %.2f", netEarnings);
}

void simpleInterest (void)
{
    system("cls");
    fundamentalInterfaceComponents();

    float principal, interestRate;
    int numberOfPeriods;

    gotoxy(30,10); printf("Enter the Principal: "); scanf("%f", &principal);
    gotoxy(30,12); printf("Enter the interest rate: "); scanf("%f", &interestRate);
    gotoxy(30,14); printf("Enter the number of periods: "); scanf("%i", &numberOfPeriods);

    float netEarnings = principal * (interestRate/100) * numberOfPeriods;
    float newPrincipal = principal + netEarnings;

    gotoxy(30,16); printf("New principal: %.2f", newPrincipal);
    gotoxy(30,18); printf("Net interes earning: %.2f", netEarnings);
}