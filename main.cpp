#include "juego.h"
#include <iostream>

using namespace std;

int main() {
    int factor, h;

    do {
        cout << "Introduce el ancho: ";
        cin >> factor;
        if (factor <= 0) {
            cout << "Debe ser un numero mayor a 0." << endl;
        }
    } while (factor <= 0);

    // Calculo del ancho
    int anchoFinal = factor * 8;


    cout << "Introduce el alto del tablero (ej: 20): ";
    cin >> h;

    // Creamos el juego con el ancho
    Juego miTetris(anchoFinal, h);
    miTetris.iniciar();

    return 0;
}
