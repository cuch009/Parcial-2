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
    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void setApellido(string a) {
        apellido = a;
    }

    string getApellido() {
        return apellido;
    }

    void setEdad(int e) {
        edad = e;
    }

    int getEdad() {
        return edad;
    }

    void setSalario(float s) {
        salario = s;
    }

    float getSalario() {
        return salario;
    }
};

int main() {
    ofstream archivo("empleados.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    int numEmpleados;
    cout << "Ingrese el numero de empleados a ingresar datos: ";
    cin >> numEmpleados;

    for (int i = 0; i < numEmpleados; ++i) {
        Empleado emp;

        string nombre, apellido;
        int edad;
        float salario;

        cout << "Empleado No." << i + 1 << ":" << endl;
        cout << "Nombre del Empleado: ";
        cin >> nombre;
        emp.setNombre(nombre);

        cout << "Apellido del Empleado: ";
        cin >> apellido;
        emp.setApellido(apellido);

        cout << "Edad del Empleado: ";
        cin >> edad;
        emp.setEdad(edad);

        cout << "Salario del Empleado: ";
        cin >> salario;
        emp.setSalario(salario);

        archivo << emp.getNombre() << " " << emp.getApellido() << " " << emp.getEdad() << " " << emp.getSalario() << endl;
    }

    archivo.close();
    cout << "Los datos han sido guardados correctamente en el archivo empleados.txt." << endl;

    return 0;
}

