using std::cin;
using std::cout;
using std::endl;

float exponenciation(float coeficient, int i){
    float interest = coeficient;
    while(i > 0){
        interest *= coeficient;
        i--;
    }
    return interest;
}

void compountInterest(void){
    float principal, interestRate;
    int numberOfCapitalizationPeriods;
    cin >> principal;
    cin >> interestRate;
    cin >> numberOfCapitalizationPeriods;

    numberOfCapitalizationPeriods--;
    float coef = (1 + interestRate/100);
    float newPrincipal = principal * exponenciation(coef, numberOfCapitalizationPeriods);
    float netEarnings = newPrincipal - principal;
    cout << "New principal: " << newPrincipal <<endl;
    cout << "Net interes earning: " <<netEarnings << endl;
}