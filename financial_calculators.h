void compountInterest(void){
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
    gotoxy(30,16); printf("New principal: %f", newPrincipal);
    gotoxy(30,18); printf("Net interes earning: %f", netEarnings);
}