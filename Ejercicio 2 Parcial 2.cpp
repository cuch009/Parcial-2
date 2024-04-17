#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    float salario;

public:
    Empleado(string n, string a, int e, float s) : nombre(n), apellido(a), edad(e), salario(s) {}

    string getNombre() {
        return nombre;
    }

    string getApellido() {
        return apellido;
    }

    int getEdad() {
        return edad;
    }

    float getSalario() {
        return salario;
    }
};

void buscarEmpleado(const string& nombreCompleto) {
    ifstream archivo("empleados.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string nombre, apellido;
    int edad;
    float salario;
    bool encontrado = false;

    while (archivo >> nombre >> apellido >> edad >> salario) {
        if (nombre + " " + apellido == nombreCompleto) {
            encontrado = true;
            cout << "Informacion del Empleado:" << endl;
            cout << "Nombre del Empleado: " << nombre << endl;
            cout << "Apellido del Empleado: " << apellido << endl;
            cout << "Edad del Empleado: " << edad << endl;
            cout << "Salario del Empleado: " << salario << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro informacion de ese empleado: " << nombreCompleto << endl;
    }

    archivo.close();
}

int main() {
    while (true) {
        string nombreCompleto;
        cout << "Ingrese el nombre completo del empleado o 'salir' para salir del buscador: ";
        getline(cin, nombreCompleto);

        if (nombreCompleto == "salir") {
            cout << "Saliendo del programa." << endl;
            break;
        }

        buscarEmpleado(nombreCompleto);
    }

    return 0;
}

