const string customfile = "usuarios.csv";

unordered_map<string, string> loadUsers(const string& customfile) {
    unordered_map<string, string> users;
    ifstream file(customfile);
    string linea, user, password;

    while (getline(file, linea)) {
        stringstream ss(linea);
        getline(ss, user, ',');
        getline(ss, password, ',');
        users[user] = password;
    }

    file.close();
    return users;
}

void registerUser(const string& customfile, const string& user, const string& password) {
    ofstream file(customfile, ios::app);
    file << user << "," << password << endl;
    file.close();
}

bool authenticateUser(const unordered_map<string, string>& users, const string& user, const string& password) {
    auto it = users.find(user);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

// To do: finnish loginBox function and delete main function of login.hpp
int main() {
    unordered_map<string, string> users = loadUsers(customfile);

    int option;
    string user, password;

    cout << "1. Register\n2. Log in\nElige una opción: ";
    cin >> option;

    if (option == 1) {
        cout << "Nombre de usuario: ";
        cin >> user;
        cout << "Contraseña: ";
        cin >> password;
        registerUser(customfile, user, password);
        cout << "Usuario registrado exitosamente.\n";
    } else if (option == 2) {
        cout << "Nombre de usuario: ";
        cin >> user;
        cout << "Contraseña: ";
        cin >> password;
        if (authenticateUser(users, user, password)) {
            cout << "Inicio de sesión exitoso.\n";
        } else {
            cout << "Nombre de usuario o contraseña incorrectos.\n";
        }
    } else {
        cout << "Opción no válida.\n";
    }

    return 0;
}

void loginBox ()
{
    system("cls");
    appearance();

    int i;

    string username;
    string password;

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

    gotoxy(38, 10); cout << "Username: "; cin >> username;
    gotoxy(38, 15); cout << "Password: "; cin >> password;
}