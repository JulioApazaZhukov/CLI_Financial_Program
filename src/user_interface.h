void border (int xs, int ys, int xi, int yi)
{
    int i;

    for(i = xs; i <= xi; i++){
        gotoxy(i, ys); printf("%c",205);
        gotoxy(i, yi); printf("%c",205);
    }

    for(i = ys; i <= yi; i++){
        gotoxy(xs, i); printf("%c",186);
        gotoxy(xi, i); printf("%c",186);
    }

    gotoxy(xs, ys); printf("%c",201);
    gotoxy(xi, yi); printf("%c",188);
    gotoxy(xs, yi); printf("%c",200);
    gotoxy(xi, ys); printf("%c",187);
}

void centerText (const char *text, int y)
{
    int lenght = strlen(text);
    gotoxy(50-(lenght/2), y); printf(text);
}

void fundamentalInterfaceComponents (void)
{
    system("cls");
    appearance();
    border(0, 0, 99, 29);
    border(2, 1, 97, 3);
    centerText("B A N K", 2);
}

void menuDisplay (double balance)
{
    fundamentalInterfaceComponents();
    gotoxy(37, 7); printf("Account balance: $"); printf("%.2f", balance);
    gotoxy(20, 11); printf("%c [1] Deposit ", 254);
    gotoxy(20, 17); printf("%c [2] Withdraw ", 254);

    gotoxy(55, 11); printf("%c [3] Lorem ", 254);
    gotoxy(55, 17); printf("%c [4] Financial calculators ", 254);
}

void calculatorMenuDisplay (void)
{
    fundamentalInterfaceComponents();
    int input;
    gotoxy(40, 10); printf("%c [1] Compound ", 254);
    gotoxy(40, 13); printf("%c [2] Simple ", 254);
    gotoxy(40, 16); printf("%c [3] Other ", 254);
    centerText("Select option: ", 22); scanf("%d", &input);
    launchCalculator(input);
}

int selectOption (int input, double balance)
{
    switch (input){
        case 1:
            dashboard(balance);   // test value
            break;
        case 5:
            calculatorMenuDisplay();
            break;
        default:
            menuDisplay(balance);
            break;
    }
    gotoxy(35, 27); system("pause");
    return 0;
}