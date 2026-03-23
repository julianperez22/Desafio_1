#include "tablero.h"

Tablero::Tablero(int w, int h) : ancho(w), alto(h), rejilla(h, std::vector<char>(w, ' ')) {}

void Tablero::limpiar() {
    for (auto& fila : rejilla) std::fill(fila.begin(), fila.end(), ' ');
}

bool Tablero::estaOcupado(int x, int y) const {
    if (x < 0 || x >= ancho || y >= alto) return true;
    if (y < 0) return false;
    return rejilla[y][x] != ' ';
}

void Tablero::fijarBloque(int x, int y, char simbolo) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto) rejilla[y][x] = simbolo;
}

char Tablero::getCelda(int x, int y) const {
    return (x < 0 || x >= ancho || y < 0 || y >= alto) ? '#' : rejilla[y][x];
}

int Tablero::borrarLineasLlenas() {
    int lineas = 0;
    for (int y = alto - 1; y >= 0; --y) {
        bool llena = true;
        for (int x = 0; x < ancho; ++x)
            if (rejilla[y][x] == ' ') llena = false; //verifica posicion por posicion si hay o no huecos
        if (llena) {
            lineas++;
            for (int k = y; k > 0; --k) rejilla[k] = rejilla[k-1];
            std::fill(rejilla[0].begin(), rejilla[0].end(), ' ');
            y++;
        }
    }
    return lineas;
}
