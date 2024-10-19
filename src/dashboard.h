void dashboard (float balance)
{
    system("cls");
    fundamentalInterfaceComponents();

    centerText("Account balance: ", 22); printf("%.2f", balance);
}