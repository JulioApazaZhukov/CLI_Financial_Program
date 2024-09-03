void border(int xs, int ys, int xi, int yi){
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

void centerText(const char *text, int y){
    int lenght = strlen(text);
    gotoxy(50-(lenght/2), y); printf(text);
}

void fundamentalInterfaceComponents(void){
    appearance();
    border(0, 0, 99, 29);
    border(2, 1, 97, 3);
    centerText("J.V. A P A Z A  &  Co", 2);
}

void loadHomeScreen(void){
    system("cls");
    fundamentalInterfaceComponents();
    menuDisplay();
}

void menuDisplay(void){
    gotoxy(20, 10); printf("%c [1] Dashboard ", 254);
    gotoxy(20, 13); printf("%c [2] Deposit ", 254);
    gotoxy(20, 16); printf("%c [3] Withdraw ", 254);

    gotoxy(55, 10); printf("%c [4] Lorem ", 254);
    gotoxy(55, 13); printf("%c [5] Financial calculators ", 254);
    gotoxy(55, 16); printf("%c [6] Ipsum ", 254);
}

int selectOption(int input){
    switch (input){
    case 5:
        compountInterest();
        break;
    default:
        loadHomeScreen();
        break;
    }
    gotoxy(35, 27); system("pause");
    return 0;
}