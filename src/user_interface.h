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
    
    gotoxy(20, 11); printf("%c [1] Dashboard ", 254);
    gotoxy(20, 14); printf("%c [2] Deposit ", 254);
    gotoxy(20, 17); printf("%c [3] Withdraw ", 254);

    gotoxy(55, 11); printf("%c [4] Lorem ", 254);
    gotoxy(55, 14); printf("%c [5] Financial calculators ", 254);
    gotoxy(55, 17); printf("%c [6] Log Out ", 254);
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

void dashboard (double balance)
{
    system("cls");
    fundamentalInterfaceComponents();

    centerText("Account balance: ", 15); printf("%.2f", balance);
}

void deposit(unordered_map<string, pair<string, double>>& users, const string& user, double amount) 
{
    if (cin.fail() || amount <= 0) {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid input. Please enter a positive number.\n";
        return; 
    }

    users[user].second += amount;
    updateCSV(customfile, users);
    gotoxy(30, 25); cout << "Successfully deposited $" << amount << ". New balance: $" << users[user].second << endl;
}

bool withdraw(unordered_map<string, pair<string, double>>& users, const string& username, double amount)
{
    if (amount < 0) {
        cerr << "Error: Cannot withdraw a negative amount.\n";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if (users[username].second < amount) {
        cerr << "Error: Insufficient balance.\n";
        return false;
    }

    users[username].second -= amount; // Update balance
    gotoxy(35, 25); cout << "Withdrew " << amount << " from " << username << "'s account.\n";
    return true;
}

void updateCSV(const string& customfile, const unordered_map<string, pair<string, double>>& users) 
{
    if (users.empty()) {
        cerr << "Error: No data to write. File update skipped.\n";
        return;
    }

    ofstream file(customfile);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for updating. Check the path or permissions: " << customfile << endl;
        return;
    }

    for (const auto& entry : users) {
        const string& user = entry.first;
        const pair<string, double>& data = entry.second;
        file << user << "," << data.first << "," << data.second << endl;
    }

    file.close();
}

int selectOption (int input, unordered_map<string, pair<string, double>>& users, const string& user, double& balance)
{
    switch (input)
    {
        case 1:
            dashboard(balance);
            break;
        case 2:
            double depositAmount;
            gotoxy(38, 23); cout << "Enter deposit amount: "; cin >> depositAmount;
            deposit(users, user, depositAmount);
            balance = users[user].second;
            break;
        case 3:
            double withdrawAmount;
            gotoxy(38, 23); cout << "Enter withdrawal amount: "; cin >> withdrawAmount;
            if (withdraw(users, user, withdrawAmount)) {
                balance = users[user].second;
            }
            break;
        case 5:
            calculatorMenuDisplay();
            break;
        case 6:
            system("cls");
            appearance();
            border(0, 0, 99, 29);
            gotoxy(38, 23); cout << "Logging out...\n";
            gotoxy(35, 25); system("pause");
            return 1;
        default:
            menuDisplay(balance);
            break;
    }
    gotoxy(35, 27); system("pause");
    return 0;
}