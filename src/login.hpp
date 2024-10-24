void loginBox ()
{
    system("cls");
    appearance();

    int i;

    int username;
    int password;

    for(i = 0; i <= 99; i++){
        gotoxy(i, 0); printf("%c",205);
        gotoxy(i, 29
    ); printf("%c",205);
    }

    for(i = 0; i <= 29; i++){
        gotoxy(0, i); printf("%c",186);
        gotoxy(99, i); printf("%c",186);
    }

    gotoxy(0, 0); printf("%c",201);
    gotoxy(99, 29); printf("%c",188);
    gotoxy(0, 29); printf("%c",200);
    gotoxy(99, 0); printf("%c",187);

    centerText("Username: ", 10); cin >> username;
    centerText("Password: ", 15); cin >> password;
}