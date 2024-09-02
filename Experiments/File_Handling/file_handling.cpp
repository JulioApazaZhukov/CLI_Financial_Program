/*#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

void readDataFile(void){
    ifstream dataFile;
    string text;
    dataFile.open("data.txt", std::ios::in);

    if (dataFile.fail()){
        cout << "Error while reading data file";
        exit(1);
    }

    while (!dataFile.eof()){
        getline(dataFile, text);
        cout << text << endl;
    }

    dataFile.close();
}

int main(void){

    readDataFile();

    system ("pause");
    return 0;
}*/
#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "ProductosExportados_SPOS3.csv"
using namespace std;

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string idProducto, codigoBarras, descripcion, precioCompra, precioVenta, existencia, stock;
        // Extraer todos los valores de esa fila
        getline(stream, idProducto, delimitador);
        getline(stream, codigoBarras, delimitador);
        getline(stream, descripcion, delimitador);
        getline(stream, precioCompra, delimitador);
        getline(stream, precioVenta, delimitador);
        getline(stream, existencia, delimitador);
        getline(stream, stock, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Id: " << idProducto << endl;
        cout << "Codigo de barras: " << codigoBarras << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio de compra: " << precioCompra << endl;
        cout << "Precio de venta: " << precioVenta << endl;
        cout << "Existencia: " << existencia << endl;
        cout << "Stock: " << stock << endl;
    }

    archivo.close();
}