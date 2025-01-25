void dashboard (double balance) // First create DB, then import saved values from user account
{
    system("cls");
    fundamentalInterfaceComponents();

    centerText("Account balance: ", 15); printf("%.2f", balance);
}