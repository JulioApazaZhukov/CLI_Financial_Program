const string customfile = "users.csv";

void registerUser(const string& customfile, const string& user, const string& password) 
{
    ofstream file(customfile, ios::app);
    file << user << "," << password << ",0" << endl;
    file.close();
}

bool authenticateUser(const unordered_map<string, pair<string, int>>& users, const string& user, const string& password, int& balance) 
{
    auto it = users.find(user);
    if (it != users.end() && it->second.first == password) { 
        balance = it->second.second; 
        return true;
    }
    return false;
}

int loginBox() 
{
    system("cls");
    appearance();
    border(0, 0, 99, 29);

    unordered_map<string, pair<string, int>> users = loadUsers(customfile);

    int option;
    string user, password;
    int balance = 0;

    while (true) 
    {
        gotoxy(38, 11); cout << "1. Register ";
        gotoxy(38, 13); cout << "2. Log in ";
        gotoxy(38, 15); cin >> option;
        
        switch (option)
        {
        case 1:
            system("cls");
            appearance();
            border(0, 0, 99, 29);
            gotoxy(38, 11); cout << "Username: "; cin >> user;
            gotoxy(38, 13); cout << "Password: "; cin >> password;
            registerUser(customfile, user, password);
            gotoxy(35, 25); cout << "User registered successfully.\n";
            gotoxy(35, 27); system("pause");
            break;
        case 2:
            system("cls");
            appearance();
            border(0, 0, 99, 29);
            gotoxy(38, 11); cout << "Username: "; cin >> user;
            gotoxy(38, 13); cout << "Password: "; cin >> password;
            if (authenticateUser(users, user, password, balance)) {
                return balance;
            } else {
                gotoxy(35, 25); cout << "Incorrect username or password.\n";
                gotoxy(35, 27); system("pause");
            }
            break;
        default:
            cout << "Invalid option.\n";
            gotoxy(35, 27); system("pause");
            break;
        }
        system("cls");
        appearance();
        border(0, 0, 99, 29);
        users = loadUsers(customfile);
    }
}