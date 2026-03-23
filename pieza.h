#ifndef PIEZA_H
#define PIEZA_H

enum TipoPieza { Vacia = 0, Z, S, Linea, T, Cuadrado, L, LInversa };

class Pieza {
public:
    Pieza();
    void establecerForma(TipoPieza tipo);
    void establecerAleatoria();
    void rotarDerecha();
    int x(int indice) const { return coordenadas[indice][0]; }
    int y(int indice) const { return coordenadas[indice][1]; }

private:
    TipoPieza tipoActual;
    int coordenadas[4][2];
};

#endif
