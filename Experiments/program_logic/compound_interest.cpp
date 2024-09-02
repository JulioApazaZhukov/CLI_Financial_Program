#include <iostream>

using namespace std;

float exponenciation(float coeficient, int i){
    float interest = coeficient;
    while(i > 0){
        interest *= coeficient;
        i--;
    }
    return interest;
}

int main(){
    float principal, interestRate;
    int nOfCap;
    cin >> principal;
    cin >> interestRate;
    cin >> nOfCap;
    
    nOfCap--;
    float coef = (1 + interestRate/100);
    float newPrincipal = principal * exponenciation(coef, nOfCap);
    float netEarnings = newPrincipal - principal;

    cout << "New principal: " << newPrincipal << endl;
    cout << "Net interes earning: " << netEarnings << endl;

    return 0;
}