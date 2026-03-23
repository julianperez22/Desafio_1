#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "pieza.h"

class Juego {
public:
    // El constructor recibe el ancho ya multiplicado y el alto
    Juego(int anchoReal, int alto);

    // Inicia el bucle de turnos cin >> comando
    void iniciar();

private:
    Tablero tablero;
    Pieza pieza;
    int px, py;      // Posición actual de la pieza
    int puntos;
    bool activo;     // Estado de la partida
    int ancho_real;  // Guardamos el ancho para ajustar el dibujo

    void nuevaPieza();
    void dibujar();
    bool mover(const Pieza& p, int nx, int ny);
    void procesarTurno(char accion);
};

#endif
