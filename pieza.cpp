#include "pieza.h"
#include <cstdlib>
#include <ctime>

// Constructor: inicializa una pieza vacía
Pieza::Pieza() {
    establecerForma(Vacia);
}

// Define la estructura de cada una de las 7 piezas
void Pieza::establecerForma(TipoPieza tipo) {

    // El punto {0,0} es el centro de rotación
    static const int tabla[8][4][2] = {
        { {0, 0},  {0, 0},  {0, 0},  {0, 0}  }, // Vacia
        { {0, -1}, {0, 0},  {-1, 0}, {-1, 1} }, // Z
        { {0, -1}, {0, 0},  {1, 0},  {1, 1}  }, // S
        { {0, -1}, {0, 0},  {0, 1},  {0, 2}  }, // Linea
        { {-1, 0}, {0, 0},  {1, 0},  {0, 1}  }, // T
        { {0, 0},  {1, 0},  {0, 1},  {1, 1}  }, // Cuadrado
        { {-1, -1}, {0, -1}, {0, 0},  {0, 1}  }, // L
        { {1, -1},  {0, -1}, {0, 0},  {0, 1}  }  // L al reves
    };

    for (int i = 0; i < 4; i++) {
        coordenadas[i][0] = tabla[tipo][i][0];
        coordenadas[i][1] = tabla[tipo][i][1];
    }
    tipoActual = tipo;
}


void Pieza::establecerAleatoria() {
    int r = (std::rand() % 7) + 1;
    establecerForma(static_cast<TipoPieza>(r));
}


void Pieza::rotarDerecha() {
    if (tipoActual == Cuadrado) return; // El cuadrado no se rota

    for (int i = 0; i < 4; ++i) {
        int temporalX = coordenadas[i][0];
        coordenadas[i][0] = -coordenadas[i][1];
        coordenadas[i][1] = temporalX;
    }
}
