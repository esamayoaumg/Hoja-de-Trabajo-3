#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};


Nodo* tope = NULL;


void push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Elemento insertado correctamente.\n";
}

//pop es eliminar
void pop() {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia.\n";
        return;
    }
    Nodo* temp = tope;
    cout << "Elemento eliminado: " << temp->dato << endl;
    tope = tope->siguiente;
    delete temp;
}

//peek es ver el tope
void peek() {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia \n";
    } else {
        cout << "Elemento en el tope:  " << tope->dato << endl;
    }
}


void mostrar() {
    if (tope == NULL) {
        cout << "La pila esta vacia\n";
        return;
    }

    Nodo* actual = tope;
    cout << "Elementos de la pila: \n";
    while (actual != NULL) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }
}


int contarElementos() {
    int contador = 0;
    Nodo* actual = tope;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void buscarElemento(int valor) {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia \n";
        return;
    }

    Nodo* actual = tope;
    int posicion = 1;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == valor) {
            cout << "Elemento encontrado en la posicion: " << posicion << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "Elemento no encontrado \n";
    }
}

void vaciarPila() {
    if (tope == NULL) {
        cout << "La pila ya esta vacia \n";
        return;
    }

    while (tope != NULL) {
        pop();
    }

    cout << "Pila vaciada completamente.\n";
}


void menu() {
    int opcion, valor;

    do {
        cout << "\n MENU PILA\n";
        cout << "Nombre: Elder Geovani Samayoa Esquivel \n";
        cout << "1. Insertar (push)\n";
        cout << "2. Eliminar (pop)\n";
        cout << "3. Ver tope (peek)\n";
        cout << "4. Mostrar pila\n";
        cout << "5. Contar elementos\n";
        cout << "6. Buscar elemento\n";
        cout << "7. Vaciar pila\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> valor;
                push(valor);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                mostrar();
                break;

            case 5:
                cout << "Cantidad de elementos: " << contarElementos() << endl;
                break;

            case 6:
                cout << "Ingresa valor a buscar: ";
                cin >> valor;
                buscarElemento(valor);
                break;

            case 7:
                vaciarPila();
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "opcion invalida \n";
        }

    } while (opcion != 8);
}


int main() {
    menu();
    return 0;
}