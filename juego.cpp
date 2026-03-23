#include "juego.h"
#include <iostream>

using namespace std;

Juego::Juego(int anchoReal, int alto)
    : tablero(anchoReal, alto), puntos(0), activo(true), ancho_real(anchoReal) {
    nuevaPieza();
}

void Juego::nuevaPieza() {
    pieza.establecerAleatoria();
    px = ancho_real / 2; // Aparece en el centro horizontal
    py = 0;              // Aparece arriba del todo

    // Si al aparecer ya está ocupado, pierde
    if (!mover(pieza, px, py)) {
        activo = false;
    }
}

bool Juego::mover(const Pieza& p, int nx, int ny) {
    for (int i = 0; i < 4; ++i) {
        // Verificamos colisiones con el tablero usando las coordenadas de la pieza
        if (tablero.estaOcupado(nx + p.x(i), ny + p.y(i))) {
            return false;
        }
    }
    pieza = p;
    px = nx;
    py = ny;
    return true;
}

void Juego::dibujar() { //nuevo tablero
    system("cls"); // Limpia la consola

    cout << "PUNTOS: " << puntos << endl << endl;

    for (int y = 0; y < tablero.getAlto(); ++y) {
        cout << "| "; // Borde izquierdo
        for (int x = 0; x < tablero.getAncho(); ++x) {


            bool esPiezaActual = false;
            for (int i = 0; i < 4; ++i) {
                if (px + pieza.x(i) == x && py + pieza.y(i) == y) {
                    esPiezaActual = true;
                    break;
                }
            }

            if (esPiezaActual) {
                cout << "[]";
            } else if (tablero.getCelda(x, y) == '#') {
                cout << "[]"; // Bloques ya fijados
            } else {
                cout << " ."; // Espacio vacío según tu imagen
            }
        }
        cout << " |" << endl; // Borde derecho
    }

    // Línea inferior dinámica: se ajusta al ancho del tablero
    // (ancho * 2 caracteres por bloque + 4 de los bordes)
    for (int i = 0; i < (ancho_real * 2) + 4; ++i) cout << "-";
    cout << endl;

    cout << "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir: ";
}

void Juego::procesarTurno(char accion) {
    // Ejecutar la acción
    switch (tolower(accion)) {
    case 'a': mover(pieza, px - 1, py); break; //Lado izq
    case 'd': mover(pieza, px + 1, py); break;
    case 'w': {
        Pieza r = pieza;
        r.rotarDerecha();
        mover(r, px, py);
        break;
    }
    case 's': break; // S solo baja y rompe para dar otra
    }

    //  Gravedad: La pieza intenta bajar un espacio CADA TURNO
    if (!mover(pieza, px, py + 1)) {
        // Si no puede bajar, la fijamos
        for (int i = 0; i < 4; ++i) {
            tablero.fijarBloque(px + pieza.x(i), py + pieza.y(i), '#');
        }
        // Limpiamos líneas y sumamos puntos si limpiamos fila
        puntos += tablero.borrarLineasLlenas() * 100;
        nuevaPieza();
    }
}

void Juego::iniciar() {
    char comando;
    while (activo) {
        dibujar();
        cin >> comando;
        if (tolower(comando) == 'q') break;
        procesarTurno(comando);
    }

    system("cls");

    cout << "      GAME OVER" << endl;
    cout << "  Puntuacion final: " << puntos << endl;
}
