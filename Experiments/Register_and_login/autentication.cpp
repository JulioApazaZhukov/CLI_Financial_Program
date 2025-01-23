#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
const string archivo = "usuarios.csv";

unordered_map<string, string> cargarUsuarios(const string& archivo) {
    unordered_map<string, string> usuarios;
    ifstream file(archivo);
    string linea, usuario, contrasena;

    while (getline(file, linea)) {
        stringstream ss(linea);
        getline(ss, usuario, ',');
        getline(ss, contrasena, ',');
        usuarios[usuario] = contrasena;
    }

    file.close();
    return usuarios;
}

void registerUser(const string& archivo, const string& usuario, const string& contrasena) {
    ofstream file(archivo, ios::app);
    file << usuario << "," << contrasena << endl;
    file.close();
}

bool autenticarUsuario(const unordered_map<string, string>& usuarios, const string& usuario, const string& contrasena) {
    auto it = usuarios.find(usuario);
    if (it != usuarios.end() && it->second == contrasena) {
        return true;
    }
    return false;
}

int main() {
    //string archivo = "usuarios.csv";
    unordered_map<string, string> usuarios = cargarUsuarios(archivo);

    int opcion;
    string usuario, contrasena;

    cout << "1. Registrar\n2. Iniciar sesión\nElige una opción: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Nombre de usuario: ";
        cin >> usuario;
        cout << "Contraseña: ";
        cin >> contrasena;
        registerUser(archivo, usuario, contrasena);
        cout << "Usuario registrado exitosamente.\n";
    } else if (opcion == 2) {
        cout << "Nombre de usuario: ";
        cin >> usuario;
        cout << "Contraseña: ";
        cin >> contrasena;
        if (autenticarUsuario(usuarios, usuario, contrasena)) {
            cout << "Inicio de sesión exitoso.\n";
        } else {
            cout << "Nombre de usuario o contraseña incorrectos.\n";
        }
    } else {
        cout << "Opción no válida.\n";
    }

    return 0;
}