

#include <iostream>
#include <stdlib.h>
#include "Pila.cpp"
#include "Cola.cpp"
#include "Lista.cpp"
#include "Gestor.cpp"

using namespace std;


Lista* lista = new Lista();
Cola* cola = new Cola();
Pila* pila = new Pila();

Gestor* gestor = new Gestor(cola,lista,pila);

void menu() {
    int opc = 0;

    do {
        cout << "\n Menu" << endl;
        cout << "(1) Llenar Lista Random " << endl;
        cout << "(2) Ejecutar Arbol" << endl;
        cout << "(3) " << endl;

        cout << "(0) Salir del programa" << endl;
        cout << "_____________________________________________________________________" << endl;
        cout << "Opcion Seleccionada-> "; cin >> opc;
        cout << endl << endl;

        switch (opc) {
            case 1: {
                gestor->generateRandomValues();
                break;
            }
            case 2: {
                gestor->ejecutarArbol();
                break;
            }
            case 3: {

                break;
            }

            default:{
                cout << "Opcion digitada no es valida. " << endl;
                break;
            }
        }

    } while (opc!=0);
}

int main()
{
    cout << "--------------------------Bienvenido--------------------------------\n" << endl;
    menu();
}

