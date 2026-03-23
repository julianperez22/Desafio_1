#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

class Tablero {
public:
    Tablero(int ancho, int alto);
    void limpiar();
    void fijarBloque(int x, int y, char simbolo);
    bool estaOcupado(int x, int y) const;
    int borrarLineasLlenas();
    char getCelda(int x, int y) const;

    int getAncho() const { return ancho; }
    int getAlto() const { return alto; }

private:
    int ancho, alto;
    std::vector<std::vector<char>> rejilla;
};

#endif
