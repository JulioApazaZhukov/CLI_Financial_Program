void externalBorder(int xs, int ys, int xi, int yi){
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

void border(int xs, int ys, int xi, int yi){
    externalBorder(xs, ys, xi, yi);
}

void borderPrinting(void){
    externalBorder(0, 0, 99, 29);
    border(2, 1, 97, 3);
}

void centerText(const char *text, int y){
    int lenght = strlen(text);
    gotoxy(50-(lenght/2), y); printf(text);
}

void staticText(void){
    centerText("J.V. A P A Z A  &  Co", 2);
}